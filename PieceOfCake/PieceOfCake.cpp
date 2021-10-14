#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int main(){
    int length;
    int horz;
    int vert;
    cin >> length;
    cin >> horz;
    cin >> vert;
    int long curMax = 0;
    vector <int long> area;
    area.push_back(horz*vert);
    area.push_back((length-horz)*vert);
    area.push_back(horz*(length-vert));
    area.push_back((length-horz)*(length-vert));
    for (int long num : area){
        if (num > curMax){
            curMax = num;
        }
    }
    cout << curMax*4 << endl;
    return 0;
}