#include <iostream>
#include <queue>
#include <set>
#include <unordered_map>
// unordered_map<string, set<string>
using namespace std;
int main() {
//map<string, set(string)

//Check artist name
    cout << "Welcome to Custer, Ethan, and Isaac's Spotify project!" << endl;
    cout << "Please enter the name of the artist you want to check:" << endl;
    string artist;
    int levelNum;
    cin >> artist;
    cout << artist << endl;
    cout << "Please enter how many iterations you want to go through for this project" << endl;
    cin >> levelNum;

    unordered_map<string, set<string>> daMap;
    queue<string> qu;
    // Same as first level
    for (string x : daMap[artist]) {
        qu.push(x);
    }
    //Vector that stores vectors for each level
    vector<vector<string>> nameStorer;
    nameStorer[0].push_back(artist);
    for (int i = 1; i < levelNum; i++) {
        if (!qu.empty()) {
            int quSize = qu.size();
            for (int j = 0; j < quSize; j++) {
                for (string x : daMap[qu.front()]) {
                    qu.push(x);
                }
                nameStorer[i].push_back(qu.front());
                qu.pop();
            }
        }
        else {
            cout << "No more levels after " << i << "th iteration";
        }

        for (i = 0; i < nameStorer.size(); i++) {
            cout << "Artists in level " << i << ":" << endl;
            string artists;
            for (string x : nameStorer[i]) {
                artists +=  x + ", " + "\n";
            }
            artists.pop_back();
            artists.pop_back();
        }

        cout << "Script finished!!!" << endl;





    }




}
