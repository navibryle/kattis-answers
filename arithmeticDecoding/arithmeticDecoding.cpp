#include <iostream>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
pair<long double,long double> updateInterval(string input,long double pA){
    pair<long double,long double> interval{0.0,1.0};
    for (char inp: input){
        long double c = interval.first + pA*(interval.second - interval.first);
        if (inp == 'A'){
            interval.second = c;
        }else{
            //must be 'B'
            interval.first = c;
        }
    }    
    return interval;
}
string numToLetter(unsigned cur,unsigned len){
    // 1 is A 0 is B
    string out{""};
    unsigned mask = 1 << (len-1);
    for (unsigned i = 0; i<len;i++){
        if ((mask & cur) == 0){
            out.push_back('B');
        }else{
            out.push_back('A');
        }
        cur = cur << 1;
    }
    return out;
}
long double toDec(string num){
    bool start =false;
    long double curPow = -1.0;
    long double out = 0;
    for (char i : num){
        if (i == '.'){
            start = true;
            continue;
        }
        if (start){
            if (i == '1'){
                out += pow(2.0,curPow);
            }
            curPow--;
        }
    }
    return out;
}
void mainRoutine(){
    pair<long double,long double> interval{0.0,1.0};
    unsigned len{0};
    long double pA{0};
    string message{""};
    string buff;
    while (cin>>buff){
        if (len == 0){
            len = strtoul(buff.c_str(),NULL,10);
        } else if (pA == 0){
            pA = strtold(buff.c_str(),NULL);
        }else if (message.compare("") == 0){
            message = buff;
        }
    }
    pA = pA/8;
    long double match = toDec(message);
    unsigned bound{pow(2.0,(double)len)-1};
    for (unsigned cur =0;cur <= bound;cur++){
        pair<long double,long double> inter = updateInterval(numToLetter(cur,len),pA);
        if ( match == inter.first){
            cout << numToLetter(cur,len)<< endl;
        }
    }

}

int main (){
    mainRoutine();
    return 0;
}
