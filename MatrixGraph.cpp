#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(std::unordered_map<std::string, std::set<std::string>>& matrixList) : matrix(matrixList.size(), std::vector<bool>(matrixList.size(), false))
{																							//initialize the vector<vector<bool>> to be the size of the map and set it all to false
	InitializeGraph(matrixList);
}

void MatrixGraph::InitializeGraph(std::unordered_map<std::string, std::set<std::string>>& matrixList)
{
	int i = 0; //keeps track of index for mapper

	//Iterate through the map and add each key to the mapper, if the key hasn't been added before, add the original artists' adj list too
	for (auto iter = matrixList.begin(); iter != matrixList.end(); ++iter)
	{
		//add artist to mapper, if they aren't already in there
		if (mapper.count(iter->first) == 0)
		{
			mapper[iter->first] = i;
			i++;

			//add their adjacent babies from their set now (iterate through the set found at the current artist's key)
			for (auto subIter = matrixList[iter->first].begin(); subIter != matrixList[iter->first].end(); ++subIter)
			{
				//if the adj artist isn't in the list already, add them
				if (mapper.count(*subIter) == 0)
				{
					mapper[*subIter] = i;
					i++;
				}
			}
		}
	}

	//Everyone is now in the mapper, but not in the matrix 2D vector, now we'll add them

	//initialize vector and set size to the size of mapper, set values to false
	matrix.clear(); //double check it's completely empty
	matrix.resize(mapper.size(), std::vector<bool>(mapper.size(), false));


	//iterate through the mapper and change the adjacent artists to "true" at each index
	for (auto iter = mapper.begin(); iter != mapper.end(); ++iter)
	{
		int currArtist = mapper[iter->first]; //gives index of current artist we're iterating on

		//iterate through the adjacent set
		for (auto subIter = matrixList[iter->first].begin(); subIter != matrixList[iter->first].end(); ++subIter)
		{
			int adjArtist = mapper[*subIter];

			if (adjArtist == currArtist)	//take out the fact that an artist appears in their own adjacency list
				continue;

			else
				matrix[currArtist][adjArtist] = true;
		}
	}
}

bool MatrixGraph::CheckArtist(std::string artist) //check the mapper to see if an artist exists
{
	if (mapper.count(artist))
		return true;
	else
		return false;
}
	
std::set<std::string> MatrixGraph::GetAdjacents(std::string artist) //return a vector that has all the "True" elements in the vector at the given index
{
	int wantedArtist = mapper[artist];	//index of the artist we want the adjacent artists of
	std::set<std::string> adjList;

	//iterate through the mapper, and check their indices within the wanted artist's adjacent vector. If "true", they're adjacent
	for (auto iter = mapper.begin(); iter != mapper.end(); ++iter)
	{
		int currArtist = iter->second;	//index of the current artist in the iteration

		if (matrix[wantedArtist][currArtist])	//if the value at the indices of the current artist and the wanted artist are true, meaning adjacent. . .
			adjList.insert(iter->first);		//push the value of the current artist into the set to be returned
	}

	return adjList;
}