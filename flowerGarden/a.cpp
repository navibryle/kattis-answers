#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long double ld;

unsigned sieve(unsigned num){
    vector<bool> nums(num-1,true);
    for (unsigned prime = 2; prime <= sqrt(num); prime++){
        unsigned primeS = pow(prime,2);
        if (nums[prime-2]){
            for (unsigned idx = primeS,idx2 = 1; idx <= num; idx = (primeS + prime*idx2),idx2++){
                nums[idx-2] = false;
            }
        }
    }
    unsigned lastPrime = 0;
    for (size_t idx = 0; idx < nums.size();idx++){
        if (nums[idx]){
            lastPrime = idx+2;
        }
    }
    return lastPrime;

}
ld l2(pair<ld,ld> coord1,pair<ld,ld> coord2){
    return sqrt(pow(coord1.first-coord2.first,2)+pow(coord1.second-coord2.second,2));
} 
void sol(vector<pair<long,long>> *coords, unsigned distance,unsigned flower){
    //coords are already sorted by priority 
    size_t totalFlowers = 0;
    int coordPoint = 0;
    pair<long,long> pos = make_pair(0,0);
    ld totalDist = 0;
    while ((totalDist + l2(pos,(*coords)[coordPoint])) <= distance && coordPoint < coords->size()){
        totalDist += l2(pos,(*coords)[coordPoint]);
        pos = (*coords)[coordPoint];
        totalFlowers++;
        coordPoint++;
    }
    if (totalFlowers == 0 || totalFlowers == 1 || distance == 0){
        cout << 0 << endl;
    }else{
        cout << sieve(totalFlowers) << endl;
    } 
}
void mr(){
    int tc;
    cin >> tc;
    for (int start = 0; start< tc; start++){
        unsigned flower;
        unsigned distance;
        cin >> flower >> distance;
        vector<pair<long,long>> coords;
        for (int start2 = 0; start2<flower;start2++){
            pair<long,long> temp;
            cin >> temp.first >> temp.second;
            coords.push_back(temp);
        }
        sol(&coords,distance,flower);
    }
}
int main(){
    mr();
    return 0;
}