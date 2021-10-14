#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
void sol(vector<string> matrix,int n,int m){

}
void mr(){
    int n;
    int m;
    cin >> n >> m;
    vector<string> matrix;
    for (int i=0;i<n;i++){
        string temp;
        cin >> temp;
        matrix.push_back(temp);
    }
    sol(matrix,n,m);
}
int main(){
    mr();
    return 0;
}