#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
enum Pos{BOTTOM=0,TOP,N,W,S,E};
Pos getOpposite(Pos pos){
    switch (pos)
    {
    case BOTTOM:
        return TOP;
    case TOP:
        return BOTTOM;
    case N:
        return S;
    case S:
        return N;
    case W:
        return E;
    case E:
        return W;
    }
}

class Node{

    //the following positions correspond to their true positions in the grid and their position in the cube
    public:
        Pos n;
        Pos s;
        Pos w;
        Pos e;
        Pos cur; // position of the current node in the cube
        Node * parent;
        pair<int,int> coord;
        vector<bool> * sides;            
        Node(Pos pos1,Pos pos2,Pos pos3,Pos pos4, Pos curPos, pair<int,int> coordInp,vector<bool> *cubeState,Node * parentArg){
            n = pos1;
            s = pos2;
            w = pos3;
            e = pos4;
            cur = curPos;
            coord = coordInp;           
            sides = cubeState;
            parent = parentArg;
        }
        bool equals(Node * node){
            if (cur == node->cur){
                return true;
            }
            return false;
        }
        bool isComplete(){
            for (bool side:*sides){
                if (!side){
                    return false;
                }
            }
            return true;
        }
        bool nv(){
            return !(*sides)[n] && coord.first > 0;
        }
        bool sv(){
            return !(*sides)[s] && coord.first < 5;
        }
        bool ev(){
            return !(*sides)[e] && coord.second < 5;
        }
        bool wv(){
            return !(*sides)[w] && coord.second > 0;
        }
        Node * getTN(){
            pair<int,int> newCoord = make_pair(coord.first-1,coord.second);
            if (parent == NULL){
                return new Node(TOP,BOTTOM,w,e,N,newCoord,sides,this);
            }
            return new Node(getOpposite(cur),cur,w,e,n,newCoord,sides,this);
        }

        Node * getTS(){
            pair<int,int> newCoord = make_pair(coord.first+1,coord.second);
            if (parent == NULL){
                return new Node(BOTTOM,TOP,w,e,S,newCoord,sides,this);
            }
            return new Node(cur,getOpposite(cur),w,e,s,newCoord,sides,this);
        }

        Node * getTW(){
            pair<int,int> newCoord = make_pair(coord.first,coord.second-1);
            if (parent == NULL){
                return new Node(n,s,TOP,BOTTOM,W,newCoord,sides,this);
            }
            return new Node(n,s,getOpposite(cur),cur,w,newCoord,sides,this);
        }

        Node * getTE(){
            pair<int,int> newCoord = make_pair(coord.first,coord.second+1);
            if (parent == NULL){
                return new Node(n,s,BOTTOM,TOP,E,newCoord,sides,this);
            }
            return new Node(n,s,cur,getOpposite(cur),e,newCoord,sides,this);
        }
};
bool isCube(vector<vector<char>> inp,pair<int,int> root){
    //BASE,N,S,E,W,TOP
    Pos curSquare = BOTTOM;
    vector<bool> sides = {true,false,false,false,false,false};
    Node * rootNode = new Node(N,S,W,E,BOTTOM,root,&sides,NULL);
    vector<Node*> stack;
    stack.push_back(rootNode);
    while (stack.size() != 0){
        Node * curNode = stack[stack.size()-1];
        if (curNode->isComplete()){
            return true;
        }
        stack.pop_back();
        if (curNode->nv()){
            Node * nNode = curNode->getTN();
            pair<int,int> newC = nNode->coord;
            if (inp[newC.first][newC.second] == '#' && !curNode->equals(nNode) && !sides[nNode->cur]){
                sides[nNode->cur] = true;
                stack.push_back(nNode);
            }
        }
        if (curNode->sv()){
            Node * nNode = curNode->getTS();
            pair<int,int> newC = nNode->coord;
            if (inp[newC.first][newC.second] == '#' && !curNode->equals(nNode) && !sides[nNode->cur]){
                sides[nNode->cur] = true;
                stack.push_back(nNode);
            }
        }
        if (curNode->ev()){
            Node * nNode = curNode->getTE();
            pair<int,int> newC = nNode->coord;
            if (inp[newC.first][newC.second] == '#' && !curNode->equals(nNode) && !sides[nNode->cur]){
                sides[nNode->cur] = true;
                stack.push_back(nNode);
            }
        }
        if (curNode->wv()){
            Node * nNode = curNode->getTW();
            pair<int,int> newC = nNode->coord;
            if (inp[newC.first][newC.second] == '#' && !curNode->equals(nNode) && !sides[nNode->cur]){
                sides[nNode->cur] = true;
                stack.push_back(nNode);
            }
        }
    }
    return false;
}
void brute(vector<vector<char>> inp){
    bool canFold = false;
    for (size_t idx1 = 0; idx1 < inp.size(); idx1++){
        for (size_t idx2 = 0; idx2 < inp[idx1].size(); idx2++){
            if (inp[idx1][idx2] == '#'){
                if (isCube(inp,make_pair(idx1,idx2))){
                    canFold = true;
                    break;
                }
            }
        }
        if (canFold){
            break;
        }
    }
    if (canFold){
        cout << "can fold" << endl;
    }else{
        cout << "cannot fold" << endl;
    }

}

void mainRoutine(){
    vector<vector<char>> inp(6);
    char buff;
    size_t idx = 0;
    while (cin >> buff){
        inp[idx].push_back(buff);
        if (inp[idx].size() == 6){
            idx++;
        }
    }
    brute(inp);
}


int main(){
    mainRoutine();        
    return 0;
}