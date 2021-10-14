#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>
using namespace std;
void sol(vector<vector<long long>> *inp){
    vector<long long> totalTime;
    for (vector<long long> cust: (*inp)){
        long long sum = 0;
        for (long long num :cust){
            sum += num;
        }
        totalTime.push_back(sum);
    }
    sort(totalTime.begin(),totalTime.end());
    double out = 0;
    double curTime = 0;
    for (long long num:totalTime){
        out += (curTime+num);
        curTime += num;
    }
    cout <<fixed<< setprecision(10) << (((double) out) /((double) totalTime.size())) << endl;
}
void mr(){
    int tc;
    cin >> tc;
    for (int start = 0;start < tc; start++){
        vector<vector<long long>> inp;
        int cust;
        cin >> cust;
        for (int startCust = 0;startCust < cust; startCust++){
           vector<long long> temp;
           int woodNum;
           cin >> woodNum;
           for (int startWood = 0 ; startWood < woodNum; startWood++ ){
               long long woodSize;
               cin >> woodSize;
               temp.push_back(woodSize);
           } 
           inp.push_back(temp);
        }
        sol(&inp);
    }
}
int main(){
    mr();
    return 0;
}