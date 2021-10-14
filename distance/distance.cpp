#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;
pair<unsigned long,unsigned long> makeCoords(string coord){
    unsigned spaceIdx = coord.find(' ');
    return make_pair(strtoul(coord.substr(0,spaceIdx).c_str(),NULL,10),strtoul(coord.substr(spaceIdx+1).c_str(),NULL,10));
}
bool compareCoors(pair<unsigned long,unsigned long> coord1,pair<unsigned long,unsigned long> coord2){
    if (coord1.first == coord2.first && coord2.second == coord1.second){
        return true;
    }
    return false;
}

unsigned long getTotalDist2(vector <pair<int long long,int long long>> coords){
    unsigned long totalDist{0};
    size_t cSize = coords.size();
    vector<int long long> xCoords;
    vector<int long long> yCoords;
    for (pair<int long long,int long long> coord: coords){
        xCoords.push_back(coord.first);
        yCoords.push_back(coord.second);
    }
    sort(xCoords.begin(),xCoords.end());
    sort(yCoords.begin(),yCoords.end());
    for (size_t idx1 = 0,idx2 = 1;idx2 < xCoords.size(); idx2++,idx1++){
        totalDist += ((abs(xCoords[idx1] - xCoords[idx2]))* ((idx1+1)*(cSize-idx2)));
    }
    for (size_t idx1 = 0,idx2 = 1;idx2 < yCoords.size(); idx2++,idx1++){
        totalDist += ((abs(yCoords[idx1] - yCoords[idx2]))* ((idx1+1)*(cSize-idx2)));
    }
    return totalDist;

}

unsigned long getTotalDist(vector <pair<int long long,int long long>> coords){
    unsigned long totalDist{0};
    vector <pair<int , int long long>> xs; 
    vector <pair<int , int long long>> ys; 
    unordered_map <string,int long long> hm;

    for (auto coord: coords){
        string keyX = to_string(coord.first)+"x";
        string keyY = to_string(coord.second)+"y";
        auto hmIterX = hm.find(keyX);
        auto hmIterY = hm.find(keyY);
        if (hmIterX != hm.end()){
            hmIterX->second++;
        }else{
            hm.insert(pair<string,int long long>(keyX,1));
        }
        if (hmIterY != hm.end()){
            hmIterY->second++;
        }else{
            hm.insert(pair<string,int long long>(keyY,1));
        }
    }
    unordered_map <string,int long long> ::iterator it;
    for (it = hm.begin() ; it != hm.end(); it++){
        if (it->first.back() == 'x'){
            int long long num = atoi(it->first.substr(0,it->first.size()-1).c_str());
            xs.push_back(make_pair(num,it->second));
        }
        if (it->first.back() == 'y'){
            int long long num = atoi(it->first.substr(0,it->first.size()-1).c_str());
            ys.push_back(make_pair(num,it->second));
        }
    } 

    sort(xs.begin(),xs.end());
    sort(ys.begin(),ys.end());
    unsigned arrXSize = xs.size();
    for (int idx1 = 0,idx2 = 1; idx2 < arrXSize; idx1++,idx2++){
        int long long segment = (abs(xs[idx1].first - xs[idx2].first));
        // totalDist += ((xs[idx1].second*xs[idx2].second)*segment) + (segment* ((idx1)*(arrXSize-idx2)));        
        totalDist += (segment* ((idx1)*(arrXSize-idx2))) + (segment * xs[idx1].second);
    }
    unsigned arrYSize = ys.size();
    for (int idx1 = 0,idx2 = 1; idx2 < ys.size(); idx1++,idx2++){
        int long long segment = (abs(ys[idx1].first - ys[idx2].first));
        // totalDist += ((ys[idx1].second*ys[idx2].second)*(abs(ys[idx1].first - ys[idx2].first))) * ((idx1+1)*(arrYSize - idx2));
        // totalDist += ((ys[idx1].second*ys[idx2].second)*segment) + (segment* ((idx1)*(arrYSize-idx2)));        
        totalDist += (segment* ((idx1)*(arrYSize-idx2))) + (segment * ys[idx1].second);
    }
    return totalDist;
}

void mainRoutine(){
    string buff;
    vector <pair<int long long,int long long>> coords;
    bool foodLen{true};
    while (getline(cin,buff,'\n')){
        if (foodLen){
            foodLen = false;
            continue;
        }else{
            coords.push_back(makeCoords(buff));
        }
    }
    cout << getTotalDist2(coords) << endl;
}

int main(){
    mainRoutine();
    return 0;

}