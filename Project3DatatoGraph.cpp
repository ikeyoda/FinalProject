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
    ifstream file;
    file.open("newfile.txt");
    string line;
    string temp = "";
    map<string, set<string>> masterList;
    while (getline(file, line)) {
        if (line.size() < 2) {
            continue;
        }
        set<string> unique = {};
        for (int i = 0; i < line.size(); i++) {
            if (line[i] != '\n' && line[i] != '^') {
                temp.push_back(line[i]);
            }
            else {
                unique.insert(temp);
                temp = "";
            }
        }
        for (auto iter = unique.begin(); iter != unique.end(); iter++) {
            if (masterList[*iter].size() == 0) {
                masterList[*iter] = unique;
            }
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
    outFile.open("output.txt");
    int count = masterList.size();
    for (auto iter = masterList.begin(); iter != masterList.end(); iter++) {
        outFile << iter->first << ":";
        for (auto iter2 = iter->second.begin(); iter2 != iter->second.end(); iter2++) {
            outFile << *iter2 << ",";
        }
        outFile << endl << endl;
        cout << count-- << endl;
    }
}   