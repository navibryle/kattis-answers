#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void padList(vector<int> * prefList,int teamSize){
    int diff = teamSize - prefList->size();
    if (diff > 0){
        for (int a = 0; a < diff ; a++){
            prefList->push_back(-1);
        }
    }
}

vector<vector<int>> tPL(vector<vector<string>> * prefList,unordered_map<string,size_t> pMap,int teamSize,vector<vector<int>> * tPrefList){
    for (size_t idx1 = 0; idx1 < prefList->size(); idx1++){
        vector<string> row = (*prefList)[idx1];
        vector<int> * tRow = &(*tPrefList)[idx1];
        for (string p: row){
            tRow->push_back(pMap[p]);
        }
        padList(tRow,teamSize);
    }
    return (*tPrefList);
}

void moveNextPos(size_t * curPos, vector<bool> * playerStatus){
    while (!(*playerStatus)[*curPos]){
        (*curPos)++;
    }
}

void printSol(vector<string> * players,vector<vector<int>> *transformedPL,int teamSize){
    for (vector<int> row : (*transformedPL)){
        for (int player: row){
            if (player >= 0 && player < players->size()){
                cout<< (*players)[player] << " ";
            }
        }
        cout << endl;
    } 
}

void sol(vector<vector<string>> * prefList, vector<string> * players,int teamSize,vector<vector<int>> * tPrefList){

    unordered_map<string,size_t> pMap;
    size_t curPos = 0;
    vector<bool> playerStatus(players->size(),true);
    for(size_t idx = 0; idx<players->size();idx++){
        //pMap can return  pMap.end() here
        pMap[(*players)[idx]] = idx;
    }

    vector<vector<int>> transformedPL = tPL(prefList,pMap,teamSize,tPrefList);
    for (int idx1 = 0; idx1 < teamSize; idx1++){
        for (size_t idx2 = 0; idx2 < transformedPL.size(); idx2++){
            if (transformedPL[idx2][idx1] == -1){
                transformedPL[idx2][idx1] = curPos;
                playerStatus[curPos] = false;
            }else if (playerStatus[transformedPL[idx2][idx1]]){
                playerStatus[transformedPL[idx2][idx1]] = false;
            }else{
                transformedPL[idx2][idx1] = curPos;
                playerStatus[curPos] = false;
            }
            moveNextPos(&curPos,&playerStatus);
        }
    }

    printSol(players,&transformedPL,teamSize);

}

void mainR(){
    int numOwners;
    int teamSize;
    cin >> numOwners;
    cin >> teamSize;
    vector<vector<string>> prefList(numOwners);
    vector<vector<int>> tPrefList(numOwners);
    size_t curOwner = 0;
    int tempSize;
    int cur = 0;
    bool isInt = true;
    int numAppended = 0;
    string buff;
    while (curOwner < numOwners){
        cin >> tempSize;
        for (int idx = 0 ; idx < tempSize; idx++){
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
    sol(&prefList,&players,teamSize,&tPrefList);
}

int main(){
    mainR();
    return 0;
}