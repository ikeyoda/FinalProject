#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <set>
using namespace std;
unordered_map<string,set<string>> returnMap()
{
    ifstream file;
    int count = 0;
    file.open("output.txt");
    string line;
    string tempKey = "";
    string tempValue = "";
    unordered_map<string, set<string>> masterList;
    while (getline(file, line)) {
        tempKey = "";
        getline(file, line);
        if (line.size() < 2) {
            continue;
        }
        set<string> tempSet = {};
        for (int i = 0; i < line.size(); i++) {
            if (line[i] != '\n' && line[i] != '︙') {
                tempKey.push_back(line[i]);
            }
            else {
                break;
            }
        }
        for (int i = tempKey.size()+1; i < line.size(); i++) {
            if (line[i] != '\n' && line[i] != '^') {
                tempValue.push_back(line[i]);
            }
            else {
                tempSet.insert(tempValue);
                tempValue = "";
            }
        }
        masterList[tempKey] = tempSet;
    }
    return masterList;
}
