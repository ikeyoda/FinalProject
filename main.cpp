#include <iostream>
#include <queue>
#include <set>
#include <unordered_map>
#include "ListGraph.cpp"
#include "MatrixGraph.cpp"
#include "Project3ReturnMap.cpp"
//#include "MatrixGraph.h"
// unordered_map<string, set<string>
using namespace std;
int main() {
//map<string, set(string)
    unordered_map<string, set<string>> daMap = returnMap();
//Check artist name
    cout << "Welcome to Custer, Ethan, and Isaac's Spotify project!" << endl;
    cout << "Please enter the name of the artist you want to check:" << endl;
    string artist;
    int levelNum;
    cin >> artist;
    cout << artist << endl;
    cout << "Please enter how many iterations you want to go through for this project:" << endl;
    cin >> levelNum;


//    set<string> underKanye;
//underKanye.insert("JayZ");

//    set<string> underJayZ;
//    underJayZ.insert("kanye");
//    underKanye.insert("Beyonce");
//    underKanye.insert("Eminem");
//    daMap["kanye"] = underKanye;
//    daMap["JayZ"] = underJayZ;
    queue<string> qu;

    MatrixGraph lookatThisGraph(daMap);
    bool isInMap = lookatThisGraph.CheckArtist(artist);
    cout << lookatThisGraph.CheckArtist(artist) << endl;

    //Vector of strings for each level
    vector<vector<string>> levelStore(levelNum);
    if (lookatThisGraph.CheckArtist(artist)) {
        qu.push(artist);
        for (int i = 0; i < levelNum; i++)  {
            if (!qu.empty()) {
                int quSize = qu.size();
                cout << quSize << endl;
                for (int j = 0; j < quSize; j++) {
                    set<string> daSet = lookatThisGraph.GetAdjacents(qu.front());
                    cout << "iteration " "" << j << endl;
                    for (auto it = daSet.begin(); it != daSet.end(); it++) {
                        qu.push(*it);
                        levelStore[i].push_back(*it);
                    }
                    qu.pop();
                }

            }
        }

    }

    set<string> daSet = lookatThisGraph.GetAdjacents(artist);
    for (auto it = daSet.begin(); it != daSet.end(); it++)
        cout << *it << endl;

    for (int i = 0; i < levelStore.size(); i++) {
        cout << "Level " << i+1 << ": " << endl;
        for (string y : levelStore[i]) {
            cout << y << endl;
        }
    }



    // Same as first level
    //vector<vector<string>> nameStorer(levelNum);








//    for (auto x = daMap[artist].begin(); x != daMap[artist].end(); ++x) {
//        qu.push(*x);
//    }
//    //Vector that stores vectors for each level
//
//    nameStorer[0].push_back(artist);
//    for (int i = 0; i < levelNum; i++) {
//        if (!qu.empty()) {
//            int quSize = qu.size();
//            for (int j = 0; j < quSize; j++) {
//                for (auto x = daMap[qu.front()].begin(); x != daMap[qu.front()].end(); ++x) {
//                    qu.push(*x);
//                }
//                nameStorer[i].push_back(qu.front());
//                qu.pop();
//            }
//        }
//        else {
//            cout << "No more levels after " << i << "th iteration";
//        }
//
//        for (i = 0; i < nameStorer.size(); i++) {
//            cout << "Artists in level " << i << ":" << endl;
//            string artists;
//            for (string x : nameStorer[i]) {
//                artists +=  x + ", " + "\n";
//            }
//            artists.pop_back();
//            artists.pop_back();
//        }
//
//        cout << "Script finished!!!" << endl;
//
//
//
//
//
//    }




}
