#include "ListGraph.h"

/* Welcome to the Adjacency-List based graph
-The class takes in Custer's unordered_map<string, set<string>> and uses a const reference
to that unordered map AS the adjacency list.
-Therefore, there are not insert

Notes for main:
Make sure to check artist BEFORE using getAdjacents
*/

ListGraph::ListGraph(std::unordered_map<std::string, std::set<std::string>>& _adjList) : adjList(_adjList)
{}

//Run CheckArtist BEFORE running GetAdjacents!!
bool ListGraph::CheckArtist(std::string artist)	//checks if an artist exists in the map (As a key)
{
	if (adjList.count(artist)) //if the key is found, return true
		return true;
	else
		return false;
}

//Only run this if you know the artist exists in the map!!
std::set<std::string>& ListGraph::GetAdjacents(std::string artist) //returns a string set of adjacent artists
{
	//When we got our data from Spotify, the artist we're looking at also appears
	//as their own featured artist in the list. This next line of code removes themselves before
	//the set is returned
	adjList[artist].erase(artist);

	return adjList[artist];
}



