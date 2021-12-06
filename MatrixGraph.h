#pragma once
#include <unordered_map>
#include <map>
#include <string>
#include <set>

/* Welcome to the Matrix-based Graph
-This graph converts Custer's unordered_map<string, set<string>> into a 2D vector<bool> where each vector is the size of the map
-At each index in the 2D array, false will indicate no adjacency, and true will indicate adjacency

*/
class MatrixGraph
{
	std::vector<std::vector<bool>> matrix;
	std::map<std::string, int> mapper; //<artist_name, index on 2D vector>

	void InitializeGraph(std::unordered_map<std::string, std::set<std::string>>& matrixList);


public:
	MatrixGraph(std::unordered_map<std::string, std::set<std::string>>& matrixList);

	bool CheckArtist(std::string artist); //check the mapper to see if an artist exists
	std::set<std::string> GetAdjacents(std::string artist); //return a vector that has all the "True" elements in the vector at the given index
};

