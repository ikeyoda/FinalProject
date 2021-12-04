#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <vector>
using namespace std;
int main()
{
    ifstream file;
    int count = 0;
    file.open("output.txt");
    string line;
    string tempKey = "";
    string tempValue = "";
    unordered_map<string, set<string>> masterList;
    //while (getline(file, line)) {
    for(int k = 0; k < 1000; k++){
        tempKey = "";
        getline(file, line);
        if (line.size() < 2) {
            continue;
        }
        set<string> tempSet = {};
        for (int i = 0; i < line.size(); i++) {
            if (line[i] != '\n' && line[i] != ':') {
                tempKey.push_back(line[i]);
            }
            else {
                break;
            }
        }
        for (int i = tempKey.size()+1; i < line.size(); i++) {
            if (line[i] != '\n' && line[i] != ',') {
                tempValue.push_back(line[i]);
            }
            else {
                tempSet.insert(tempValue);
                tempValue = "";
            }
        }
        masterList[tempKey] = tempSet;
    }
    for (auto iter = masterList["102 Boyz"].begin(); iter != masterList["102 Boyz"].end(); iter++) {
        cout << *iter << endl;
    }
}