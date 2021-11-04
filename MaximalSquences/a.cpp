#include<vector>
#include<algorithm>
#include<iostream>
#include<cmath>
#include <bitset>

using namespace std;
class Block{
    //indexes will be inclusive
    public:

        long double prod = 1;
        bool has1 = false;
        bool has0 = false;
        size_t startIdx = 0;
        size_t endIdx = 0;
}; vector<long double> sieve(unsigned num){
    vector<bool> nums(num-1,true);
    for (unsigned prime = 2; prime <= sqrt(num); prime++){
        unsigned primeS = pow(prime,2);
        if (nums[prime-2]){
            for (unsigned idx = primeS,idx2 = 1; idx <= num; idx = (primeS + prime*idx2),idx2++){
                nums[idx-2] = false;
            }
        }
    }
    vector<long double> primes;
    for (size_t idx = 0; idx < nums.size();idx++){
        if (nums[idx]){
            primes.push_back(idx+2);
        }
    }
    return primes;

}

void fillInBlock(size_t * seqIdx,vector<long double> * seq,vector<Block> * out,size_t idx,size_t blockSize,vector<long double> * primes){
    (*out)[idx].startIdx = *seqIdx;
    unordered_map<long double,bool> hm;
    for(size_t curBlockSize = 0;curBlockSize < blockSize && (*seqIdx )< seq->size();++(*seqIdx),curBlockSize++){
        if ((*seq)[*seqIdx] == 1){
            (*out)[idx].has1 = true;
        }else if((*seq)[*seqIdx] == 0){
            (*out)[idx].has0 = true;
        }else{
            if (hm.find((*seq)[*seqIdx]) == hm.end()){
                (*out)[idx].prod *= (*primes)[(*seq)[*seqIdx]];
                hm[(*seq)[*seqIdx]] = true;
            }
        }

    }
    (*out)[idx].endIdx = (*seqIdx) - 1;

}
vector<Block> preProc(vector<long double> * seq,vector<long double> * primes){
    size_t blockSize = ceil(sqrt(seq->size()));
    vector<Block> out(blockSize);
    size_t seqIdx = 0;
    for (size_t idx = 0; idx < out.size(); ++idx){
        if ((seq->size() - seqIdx) <= blockSize){
            //last block
            fillInBlock(&seqIdx,seq,&out,idx,blockSize,primes);
            return out;
        }else{
            //more than one block can be formed in the array
            fillInBlock(&seqIdx,seq,&out,idx,blockSize,primes);
        }

    }
}
bool isEmpty(Block b){
    return b.prod == 1 && !b.has0 && !b.has1 && b.startIdx == b.endIdx;
}
bool isInBlock(Block seqBlock,Block B){
    if (seqBlock.prod ==1){
        return B.has0 == seqBlock.has0 && B.has1 == seqBlock.has1;
    } else if (B.prod == 1){
        if (seqBlock.prod != 1){
            return true;
        }else{
            return B.has0 == seqBlock.has0 && B.has1 == seqBlock.has1;
        }
    }else{
        return  B.has0 == seqBlock.has0 && B.has1 == seqBlock.has1 && B.prod/seqBlock.prod == floor(B.prod/seqBlock.prod);
    }
}
size_t idxInBlock(vector<Block> * seqProc,size_t seqIdx){
    (seqIdx - (seqIdx/ seqProc->size()));    
}
void sol(vector<Block> * seqProc,size_t idx,unordered_map<long double,bool> * hm,vector<long double> * seq,Block B){
    size_t blockIdx = (idx/seqProc->size()); // integer division, add one to check the next block
    unsigned tot = 0;
    if ((idx+1) % seqProc->size() != 0){
        while (idx <= (*seqProc)[blockIdx].endIdx){
            if (hm->find((*seq)[idx]) == hm->end()){
                cout << tot << endl;
                return;
            }
            idx++;
            tot++;
        }
        blockIdx++;
    }
    for(;blockIdx < seqProc->size();blockIdx++){
        if (isEmpty((*seqProc)[blockIdx])){
            continue;
        }else if (blockIdx == seqProc->size()-1){
            //we are in the last block
            tot += (*seqProc)[blockIdx].endIdx - (*seqProc)[blockIdx].startIdx + 1;
            cout << tot << endl;
            return;
        }else if (isInBlock((*seqProc)[blockIdx],B)){
            tot += seqProc->size();// add the blocksize to the total
        }else{
            // the sequence ends on this block
            for (size_t startIdx = (*seqProc)[blockIdx].startIdx,endIdx=(*seqProc)[blockIdx].endIdx ;startIdx <= endIdx; startIdx++){
                if (hm->find((*seq)[startIdx]) == hm->end()){
                    cout << tot << endl;
                    return;
                }
                tot++;
            }
        }
    }
    cout << tot << endl;

}
void mr(){
    vector<long double> primes = sieve(1299710);
    int n;
    cin >> n;
    vector<long double> seq;
    for (int start =0;start<n;start++){
        long double temp;
        cin >> temp;
        seq.push_back(temp);
    }
    vector<Block> seqProc = preProc(&seq,&primes);
    unsigned long q;
    cin >> q;
    for (unsigned start = 0; start < q;start++){
        int i;
        int m;
        cin >> i >> m;
        vector<long double> B;
        unordered_map<long double,bool> hm;
        Block block;
        for (int start2 = 0; start2 < m;start2++){
            long double temp;
            cin >> temp;
            hm[temp] = true;
            if (temp == 1){
                block.has1 = true;
            } else if (temp == 0){
                block.has0 = true; 
            }else{
                block.prod *= temp;
            }
            B.push_back(temp);
        }
        sol(&seqProc,i-1,&hm,&seq,block);
    }
}

int main(){
    // mr();
    // cout << (int) sqrt (10 + .0) + 1 << endl;
    return 0;
}