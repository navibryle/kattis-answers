#include <algorithm>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;
int main(){
    int numOwners;
    int teamSize;
    cin >> numOwners;
    cin >> teamSize;
    vector<vector<string>> prefList(numOwners);
    vector<vector<string>> picked(numOwners);
    size_t curOwner = 0;
    int tempSize;
    int cur = 0;
    bool isInt = true;
    int numAppended = 0;
    string buff;
    while (curOwner < numOwners){
        cin >> tempSize;
        for (size_t idx = 0 ; idx < tempSize; idx++){
            cin >> buff;
            prefList[curOwner].push_back(buff);
        }
        curOwner++;
    }
    int playerSize;
    cin >> playerSize;
    vector<string> players;
    while (cin>>buff){
        players.push_back(buff);
    }
    unsigned long long totalSelected = 0;
    unsigned long long maxSelected = numOwners * teamSize;
    while (totalSelected < maxSelected){
        for (size_t owner = 0; owner<prefList.size();owner++){
            //check preference list
            bool didPick = false;
            if (picked[owner].size() < teamSize){
                for (size_t idx1 = 0 ;idx1<prefList[owner].size();idx1++){
                    for (size_t idx2 = 0 ;idx2<players.size();idx2++){
                        //check if player in preference list is in the player list
                        if (players[idx2].compare(prefList[owner][idx1]) == 0){
                            didPick = true;
                            picked[owner].push_back(players[idx2]);
                            players.erase(players.begin()+idx2);
                            prefList[owner].erase(prefList[owner].begin()+idx1);
                            break;
                        }
                    }
                    if (didPick){
                        break;
                    }
                }
                if (!didPick){
                    picked[owner].push_back(players[0]);
                    players.erase(players.begin());
                }
                totalSelected++;
            }
        }
    }

    for (vector<string> pick : picked){
        string out = "";
        for (size_t idx = 0; idx < pick.size() ; idx++){
            if (idx == pick.size()-1){
                out += pick[idx];
            }else{
                out += pick[idx]+" ";
            }
        }
        cout << out << endl;
    }

    return 0;
}