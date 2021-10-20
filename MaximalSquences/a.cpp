#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
void sol(vector<unsigned> * nums,int i,unordered_map<unsigned,bool> *hm){
    unsigned tot = 0;
    for (int start = i-1;start<nums->size();start++){
        if ((*hm).find((*nums)[start]) == (*hm).end()){
            cout <<  tot << endl;
            return;
        }else{
            tot++;
        }
    }
    cout << tot << endl;
}
void mr(){
    int n;
    cin >> n;
    vector<unsigned> seq;
    for (int start =0;start<n;start++){
        unsigned temp;
        cin >> temp;
        seq.push_back(temp);
    }
    unsigned long q;
    cin >> q;
    for (unsigned start = 0; start < q;start++){
        int i;
        int m;
        cin >> i >> m;
        vector<unsigned> B;
        unordered_map<unsigned,bool> hm;
        for (int start2 = 0; start2 < m;start2++){
            unsigned temp;
            cin >> temp;
            hm[temp] = true;
        }
        sol(&seq,i,&hm);
    }

}
int main(){
    mr();
    return 0;
}