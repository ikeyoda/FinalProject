//Intermediate program. This is used to transform the still raw data from the python code into a much cleaner and quicker format for the main program.
//Since this program takes several minutes to run, it is run separately and the output here is the input for the main program.
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <map>
#include <set>
#include <vector>
using namespace std;
int main()
{
    //Open newfile.txt, the output from the Python program.
    ifstream file;
    file.open("newfile.txt");
    string line;
    string temp = "";
    //Create a map of strings to a set of strings
    map<string, set<string>> masterList;
    while (getline(file, line)) {
        //First check if the line is empty or contains an actual name
        if (line.size() < 2) {
            continue;
        }
        //A set of unique names
        set<string> unique = {};
        //read through the line, using the ^ delimeter created by the Python code to get each name on the line and push it to the set.
        for (int i = 0; i < line.size(); i++) {
            if (line[i] != '\n' && line[i] != '^') {
                temp.push_back(line[i]);
            }
            else {
                unique.insert(temp);
                temp = "";
            }
        }
        //Next we will manipulate the map. Iterate through the given set. If the current name isn't already in the map, add it, and its set is just unique.
        for (auto iter = unique.begin(); iter != unique.end(); iter++) {
            if (masterList[*iter].size() == 0) {
                masterList[*iter] = unique;
            }
            //If the current name is already in the map, then add each new value to the current name's adjacent map. This nested for loop creates most of the time cost.
            else {
                for (auto iter2 = unique.begin(); iter2 != unique.end(); iter2++) {
                    masterList[*iter].insert(*iter2);
                }
            }
        }
    }
    file.close();
    cout << masterList.size();
    ofstream outFile;
    //Now create an ouput file to write the map to.
    outFile.open("output.txt");
    int count = masterList.size();
    //First add the first name, then a | character, the name before the | represents the key.
    for (auto iter = masterList.begin(); iter != masterList.end(); iter++) {
        outFile << iter->first << "|";
        //Then add each name in that person's adjacency set, delimited by ^.
        for (auto iter2 = iter->second.begin(); iter2 != iter->second.end(); iter2++) {
            outFile << *iter2 << "^";
        }
        outFile << endl;
        cout << count-- << endl;
    }
    //At the end, an output file output.txt is created with every name, around 140,000, in the data set followed by |, then followed by every adjacent name, separated by ^.
}
