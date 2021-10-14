#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
void mr(){
    int periods;
    cin >> periods;
    double total = 0;
    for (int num = 0; num < periods; num++){
        double qol;
        double time;
        cin >> qol >> time;
        total += qol*time;
    }
    cout << total << endl;
}
int main(){
    mr();
    return 0;
}