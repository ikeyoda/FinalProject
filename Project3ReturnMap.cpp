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
    file.open("/Users/isaacyoder/CLionProjects/finalProjFile/output.txt");

    string line;
//    getline(file, line);
//    cout << line << endl;
    string tempKey = "";
    string tempValue = "";
    unordered_map<string, set<string>> masterList;
    int counter = 145000;
    while (getline(file, line)) {
        tempKey = "";
        set<string> tempSet = {};
        for (int i = 0; i < line.size(); i++) {
            if (line[i] != '|') {
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
        if (masterList.size() == 254) {
            cout << "hello";
        }
        if (masterList.size() == 255) {
            cout << "hello";
        }

    }
    return masterList;
}
