#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
void mainRoutine(){
    vector<unsigned> inp;
    string input;
    while (cin>>input){
        inp.push_back(strtoul(input.c_str(),NULL,10));
    }
    unsigned len{0};
    unsigned prev{0};
    bool isOn{false};
    unsigned totalTime{0};
    for (unsigned num : inp){
        if (len == 0){
            len = num;
        }else{
            if (isOn){
                totalTime += (num-prev);
                isOn = false;
            }else{
                isOn = true;
                prev = num;
            }
        
        }

    }
    if (len%2 == 1){
        cout << "still running" << endl;
    }else{
        cout << totalTime << endl;
 
    }
}
int main(){
    mainRoutine();
    return 0;
}