#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <set>
using namespace std;
//Final function to be actually implemented in main. Order goes SpotifyWebApi.py (Python) > newfile.txt > DatatoGraph.cpp > output.txt > ReturnMap > main.
//This chain is used to optimize main and only need the several hour run time of earlier programs to only have to run once.
unordered_map<string,set<string>> returnMap()
{
    ifstream file;
    int count = 0;
    //Open the output.txt file. Currently implemented as an absolute directory, but simply "output.txt" as a relative one should work as well.
    file.open("/Users/isaacyoder/CLionProjects/finalProjFile/output.txt");
    
    string line;
    string tempKey = "";
    string tempValue = "";
    //masterList is the eventual return of the function.
    unordered_map<string, set<string>> masterList;
    //While loop iterates through each line of the output.txt
    while (getline(file, line)) {
        tempKey = "";
        set<string> tempSet = {};
        //First, the key is generated. This for loop loops through the current line until it hits the | delimeter indicating the end of the key.
        for (int i = 0; i < line.size(); i++) {
            if (line[i] != '|') {
                tempKey.push_back(line[i]);
            }
            else {
                break;
            }
        }
        //Once we have the key, iterate through the rest of the line.
        for (int i = tempKey.size()+1; i < line.size(); i++) {
            //Here we use the ^ delimeter. Whenever one is found, the current value is pushed onto a set and then cleared. This fills up the set with every name after the key.
            if (line[i] != '\n' && line[i] != '^') {
                tempValue.push_back(line[i]);
            }
            else {
                tempSet.insert(tempValue);
                tempValue = "";
            }
        }
        //Finally, the masterList creates a value at the key (the first name on the line) and sets it equal to the set (all of the following names on the line).
        //This represents an adjacency list, the key is the node, and the set is all the adjacent names.
        masterList[tempKey] = tempSet;
        //Then, everything resets, the while loop loops, and the next line is handled.
    }
    //Once the while loop is finished, the unordered_map is complete with ~140,000 unique keys, all mapped to every artist they have appeared on an album with.
    //This map is returned to be used to construct each of the graph objects implemented in main.
    return masterList;
}
