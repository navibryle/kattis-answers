#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
string removeTrailZer(string dec){
    bool inTrail = true;
    for (int idx = dec.size()-1; idx >= 0; idx--){
        if (inTrail){
            if (dec[idx] == '0'){
                continue;
            }else{
                return dec.substr(0,idx+1);
            }
        }    
    }
    return "";

}
void mr(){
    string N;
    string M;
    cin >> N >> M;
    unsigned numZeros = M.size()-1;
    if (numZeros < N.size()){
        string out = N.substr(0,N.size()-numZeros);
        string dec = N.substr(N.size()-numZeros,numZeros);
        string outDec = removeTrailZer(dec);
        if (outDec == "" && out == ""){
            cout << 0 << endl;
        }else if (outDec == ""){
            cout << out << endl;
        }else if(out == ""){
            cout << "0." << outDec << endl;
        }else{
            cout << out << "." << outDec << endl;
        }
    }else{
        string zer(numZeros-N.size(),'0');
        cout << "0." << zer << removeTrailZer(N) << endl;
    }

}
int main(){
    mr();
    return 0;
}