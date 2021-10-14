#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(){
    long unsigned num;
    cin >> num;
    if (num %2 == 0){
        cout << "Bob" << endl;
    } else{
        cout << "Alice" << endl;
    }
}