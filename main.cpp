#include <iostream>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include "ListGraph.cpp"
#include "MatrixGraph.cpp"
#include "Project3ReturnMap.cpp"
using namespace std;
int main() {
    // Map that stores artists and their connections
    unordered_map<string, set<string>> daMap = returnMap();
    cout << "Map size = " << daMap.size() << endl;
//Check artist name
    cout << "Welcome to Custer, Ethan, and Isaac's Spotify project!" << endl;
    bool runLevel = true;
    // Loop to run project
    while (runLevel == true) {
        cout << "Please enter the name of the artist you want to check: ";
        string artist;
        int levelNum;
        getline(cin, artist);
        cout << artist << endl;
        cout << "Please enter how many iterations you want to go through for this project:" << endl;
        cin >> levelNum;
        cout << "Please enter 1 for Adjacency Matrix and 2 for Adjacency List:" << endl;
        int menuSelect;
        cin >> menuSelect;
        cin.ignore(256, '\n');
        // Menu for determining which data structure to run
        if (menuSelect == 1) {
            MatrixGraph lookatThisGraph(daMap);
            queue<string> qu;
            //Checks if artists exists in map
            bool isInMap = lookatThisGraph.CheckArtist(artist);
            //Vector of strings for each level
            vector<vector<string>> levelStore(levelNum);
            if (isInMap) {
                qu.push(artist);
                unordered_set<string> alreadyIncluded;
                //Uses queue to store data for each level, and then uses a set to see if the artists was included in a previous generation
                for (int i = 0; i < levelNum; i++) {
                    if (!qu.empty()) {
                        int quSize = qu.size();
                        for (int j = 0; j < quSize; j++) {
                            set<string> daSet = lookatThisGraph.GetAdjacents(qu.front());
                            for (auto it = daSet.begin(); it != daSet.end(); it++) {
                                if (alreadyIncluded.find(*it) == alreadyIncluded.end() && *it != artist) {
                                    alreadyIncluded.insert(*it);
                                    qu.push(*it);
                                    levelStore[i].push_back(*it);
                                }
                            }
                            qu.pop();
                        }
                    }
                }

            }
            else {
                cout << "Artist not in data" << endl;
                continue;
            }

            set<string> daSet = lookatThisGraph.GetAdjacents(artist);
            //Prints artists in set
            for (int i = 0; i < levelStore.size(); i++) {
                cout << "Level " << i + 1 << ": " << endl;
                if (levelStore[i].size() == 0) {
                    cout << "There are no more artists to include!" << endl;
                    break;
                }
                for (string y : levelStore[i]) {
                    cout << y << endl;
                }
            }
        } else if (menuSelect == 2) {
            //This section is the same as above, using the Adjacency List instead of the adjacency matrix
            ListGraph lookatThisGraph(daMap);
            queue<string> qu;
            bool isInMap = lookatThisGraph.CheckArtist(artist);
            //Vector of strings for each level
            vector<vector<string>> levelStore(levelNum);
            if (isInMap) {
                qu.push(artist);
                unordered_set<string> alreadyIncluded;
                for (int i = 0; i < levelNum; i++) {
                    if (!qu.empty()) {
                        int quSize = qu.size();
                        for (int j = 0; j < quSize; j++) {
                            set<string> daSet = lookatThisGraph.GetAdjacents(qu.front());
                            for (auto it = daSet.begin(); it != daSet.end(); it++) {
                                if (alreadyIncluded.find(*it) == alreadyIncluded.end() && *it != artist) {
                                    alreadyIncluded.insert(*it);
                                    qu.push(*it);
                                    levelStore[i].push_back(*it);
                                }
                            }
                            qu.pop();
                        }
                    }
                }
            }
            else {
                cout << "Artist not present in data";
                break;
            }

            set<string> daSet = lookatThisGraph.GetAdjacents(artist);

            for (int i = 0; i < levelStore.size(); i++) {
                cout << "Level " << i + 1 << ": " << endl;
                if (levelStore[i].size() == 0) {
                    cout << "There are no more artists to include!" << endl;
                    break;
                }
                for (string y : levelStore[i]) {
                    cout << y << endl;
                }
            }
        }
        else if (menuSelect == 3) {
            cout << "Goodbye!" << endl;
            runLevel = false;
        }
    }




}
