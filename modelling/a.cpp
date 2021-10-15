#include <algorithm>
#include <iostream>
#include <vector>
#include <regex>
#include <bits/stdc++.h>
using namespace std;


bool isDigit(string s){
    char *p;
    strtol(s.c_str(),&p,10);
    if (*p){
        return false;
    }
    return true;
}

void procAssign(unordered_map<char,unordered_set<int>> *hm,string statement){
        string val= statement.substr(3,statement.size()-4);
        if (val.compare("?") == 0){
            (*hm)[statement[1]] = unordered_set<int>({0,1});
        }else if(isDigit(val)){
            (*hm)[statement[1]] = unordered_set<int>({stoi(val)});
        }else{
            unordered_set<int> var1 = {0};
            unordered_set<int> var2 = {0};
            if (hm->find(val[0]) != hm->end()){
                var1 = (*hm)[val[0]];
            }
            if (hm->find(val[2]) != hm->end()){
                var2 = (*hm)[val[2]];
            }

            unordered_set<int> newAns;
            for (int num1:var1){
                for (int num2:var2){
                    newAns.insert(num1+num2);
                }
            }
            (*hm)[statement[1]] = newAns;
        }
}

bool isLessThan(unordered_set<int> *var1,unordered_set<int> *var2){
    for (int num1:(*var1)){
        for (int num2:(*var2)){
            if (!(num1 < num2)){
                return false;
            }
        }
    }
    return true;
}
bool isEqual(unordered_set<int> * var1,unordered_set<int> * var2){
    // if (var1->size() == 1 && var2->size() == 1 && var1[0] == var2[0]){
    //    return true; 
    // }
    // return false;
    for (int num1:(*var1)){
        for (int num2:(*var2)){
            if (num1 != num2){
                return false;
            }
        }
    }
    return true;
}
bool sol(unordered_map<char,unordered_set<int>> *hm,string * statement){
    bool assertFail = false;
    regex blockMatcher("\\[.+?\\]|\\(.+?\\)|\\<.+?\\>");
    auto blockStart = sregex_iterator(statement->begin(),statement->end(),blockMatcher);
    auto blockEnd = sregex_iterator();
    for (sregex_iterator start = blockStart;start != blockEnd;++start){
        smatch block = *start;
        string state = block.str();
        switch (state[0]){
        case '[': 
            procAssign(hm,state);
            break;
        case '(':{
            unordered_set<int> var1 = {0};
            unordered_set<int> var2 = {0};
            if (hm->find(state[1]) != hm->end()){
                var1 = (*hm)[state[1]];
            }
            if (hm->find(state[3]) != hm->end()){
                var2 = (*hm)[state[3]];
            }
            if (isLessThan(&var1,&var2)){
                string nestedStatement = state.substr(5,state.size()-7);
                if (sol(hm,&nestedStatement)){
                    //assert failed in nested block
                    return true;
                }
            }
            break;
        }
        case '<':
            unordered_set<int> var1 = {0};
            unordered_set<int> var2 = {0};
            if (hm->find(state[1]) != hm->end()){
                var1 = (*hm)[state[1]];
            }
            if (hm->find(state[3]) != hm->end()){
                var2 = (*hm)[state[3]];
            }
            if (!isEqual(&var1,&var2)){
                assertFail = true;
            }
            break;
        }
    }
    return assertFail;
}
void mr(){
    int tc;
    cin >> tc;
    for (int start = 0; start < tc; start++){
        string statement;
        unordered_map<char,unordered_set<int>> hm;
        cin >> statement;
        if (sol(&hm,&statement)){
            cout << "ASSERTIONS INVALID" << endl;
        }else{
            cout << "ASSERTIONS ALWAYS HOLD" << endl;
        }
    }
}
int main(){
    mr();
    return 0;
}