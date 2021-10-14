#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
void brute(vector<int long long> nums,int long long divisor){
    int long long total = 0;
    unordered_map<int long long,int long long> count;
    for (int num:nums){
        int long long key = num/divisor;
        if (count.find(key) != count.end()){
            count[key]++;
        }else{
            count[key] = 1;
        }
    }    
    unordered_map<int long long, int long long>::iterator countIt;
    for (countIt = count.begin(); countIt != count.end(); countIt++){
        if ( countIt->second >0){
            total += (countIt->second*(countIt->second-1))/2; 
        }
    }
    cout << total << endl;
}

void mainRoutine(){
    int long len;
    int long long divisor;
    vector<int long long> nums;
    cin >> len;
    cin >> divisor;
    while (nums.size() < len){
        int long long temp;
        cin >> temp;
        nums.push_back(temp);
    }
    brute(nums,divisor);
}

int main(){
    mainRoutine();
    return 0;
}