#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void reverseString(string *inp){
    int idx1 = 0;
    int idx2 = inp->size()-1;
    while (idx1 < idx2){
        char temp = (*inp)[idx2];
        (*inp)[idx2] = (*inp)[idx1];
        (*inp)[idx1] = temp;
        idx1++;
        idx2--;
    }
}

void reverse(vector<string> *inp){
    int idx1 = 0;
    int idx2 = inp->size()-1;
    while (idx1 < idx2){
        string temp = (*inp)[idx2];
        (*inp)[idx2] = (*inp)[idx1];
        (*inp)[idx1] = temp;
        reverseString(&(*inp)[idx1]);
        reverseString(&(*inp)[idx2]);
        idx1++;
        idx2--;
    }
}

void mr(){
    int tc;
    cin >> tc;
    vector<vector<string>> inp;
    for (int start = 0; start < tc; start++){
        int row;
        int col;
        cin >> row;
        cin >> col;
        inp.push_back(vector<string>());
        for (int startRow = 0; startRow < row; startRow++){
            string temp;
            cin >> temp;
            inp[start].push_back(temp);
        }
        reverse(&inp[start]);
        cout << "Test " << start+1 << endl;
        for (int startRow = 0; startRow < row; startRow++){
            cout << inp[start][startRow] << endl;
        }
    }

}

void testString(){
    cout << "reverse string test " << endl;
    string t1 = "abcd";
    string t2 = "abc";
    reverseString(&t1);
    reverseString(&t2);
    cout << t1 << endl;
    cout << t2 << endl;

}

void reverseList(){
    cout << "reverse list test" << endl;
    vector<string> t1 = {"a","b","c","d"};
    vector<string> t2 = {"a","b","c"};
    reverse(&t1);
    reverse(&t2);
    for (string c: t1) cout << c << " ";
    cout << endl;
    for (string c: t2) cout << c << " ";
    cout << endl;
}
int main(){
    mr();
}