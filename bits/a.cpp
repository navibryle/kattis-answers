#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
void countBits(unsigned long * count,unsigned long * num){
    unsigned long mask = 1;
    while (*num != 0){
        if ((mask & (*num))  == 1){
            (*count)++;
        }
        *num = (*num) >> 1;
    }
}
void mr(){
   int tc;
   cin >> tc;
    for (int start = 0;start < tc;start++){
        string tempS;
        cin >> tempS;
        unsigned long maxB = 0;
        for (int idx = 1; idx <= tempS.size();idx++){
            unsigned long num = stoul(tempS.substr(0,idx));
            unsigned long count = 0;
            countBits(&count,&num);
            if (count > maxB){
                maxB = count;
            }
        }
        cout << maxB << endl;
        
    }
}
int main(){
    mr();
}