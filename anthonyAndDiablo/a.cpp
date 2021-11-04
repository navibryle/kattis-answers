#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void mr(){
    float A;
    float N;
    long double pi = 3.141592653589793238462643383279502884L; 
    cin >> A >> N;
    if (N >= sqrt(A*4*pi)){
        cout << "Diablo is happy!" << endl;
    }else{
        cout << "Need more materials!" << endl;
    }
}
int main(){
    mr();
    return 0;
}
