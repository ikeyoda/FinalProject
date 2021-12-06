#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(std::unordered_map<std::string, std::set<std::string>>& matrixList) : matrix(matrixList.size(), std::vector<bool>(matrixList.size(), false))
{																							//initialize the vector<vector<bool>> to be the size of the map and set it all to false
	InitializeGraph(matrixList);
}

void MatrixGraph::InitializeGraph(std::unordered_map<std::string, std::set<std::string>>& matrixList)
{
	int i = 0;
	//Iterate through the map and add each key to the mapper
	for (auto iter = matrixList.begin(); iter != matrixList.end(); ++iter)
	{
		//add artist to mapper
		mapper[iter->first] = i;
		i++;
	}

	//iterate through the map and change the adjacent artists to "true" at each index
	for (auto iter = matrixList.begin(); iter != matrixList.end(); ++iter)
	{
		int currArtist = mapper[iter->first];

		//to do this, we will iterate through the adjacent sets
		for (auto it = matrixList[iter->first].begin(); it != matrixList[iter->first].end(); ++it)
		{
			int adjArtist = mapper[*it];

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
			adjList.insert(iter->first);		//push the value of the current artist into the vector to be returned
	}

	return adjList;
}