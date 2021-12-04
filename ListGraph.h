#pragma once
#include <unordered_map>
#include <string>
#include <set>

/* Welcome to the Adjacency-List based graph
-The class takes in Custer's unordered_map<string, set<string>> and uses a const reference
to that unordered map AS the adjacency list.
-Therefore, there are not insert 
*/

class ListGraph
{
	std::unordered_map<std::string, std::set<std::string>>& adjList;
	//Key = string artist, value = set adjacent artists in string form

public:
	ListGraph(std::unordered_map<std::string, std::set<std::string>>& _adjList);
	
	bool CheckArtist(std::string artist);	//checks if an artist exists in the map (As a key)
	std::set<std::string>& GetAdjacents(std::string artist); //returns a string set of adjacent artists
};

