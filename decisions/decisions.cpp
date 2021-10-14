#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
class Node{
    public:
        Node * right;
        Node * left;
        int val;
        Node(Node *r,Node *l,int v){
            right = r;
            left = l;
            val = v;
        }
};
bool isLeaf(Node * node){
    return node->right == NULL && node->left == NULL;
}
void cleanup(Node * node){
    if (isLeaf(node)){
        return;
    }
    if(!isLeaf(node->left)){
        cleanup(node->left);
    }
    if (!isLeaf(node->right)){
        cleanup(node->right);
    }
    if (isLeaf(node->left) && isLeaf(node->right)){
        if (node->left->val == -1 && node->right->val == -1){
            node->left = NULL;
            node->right = NULL;
        }else if(node->left->val == node->right->val){
            node->val = node->right->val; 
            node->left = NULL;
            node->right = NULL;
        }else if(node->left->val == -1 && node->right->val != -1){
            node->val = node->right->val; 
            node->left = NULL;
            node->right = NULL;
        }else if(node->right->val == -1 && node->left->val != -1){
            node->val = node->left->val; 
            node->left = NULL;
            node->right = NULL;
        }

    }
}
void countNodes(Node * node,long * total){
    (*total)++;
    if (node->right != NULL){
        countNodes(node->right,total);
    }
    if (node->left != NULL){
        countNodes(node->left,total);
    }
}
void sol(vector<unsigned> inp){
    Node * root = new Node(NULL,NULL,-1);
    Node * curNode = root;
    Node * parent;
    for (size_t idx = 0;idx<inp.size();idx++){
        unsigned temp = idx;
        if (temp == 0){
            root->left = new Node(NULL,NULL,inp[idx]);
            parent = root;
        }else{
            while(temp!=0){
                unsigned temp2 = temp & 1;
                parent = curNode;
                if (temp2 == 1){
                    if (curNode->right == NULL){
                        curNode->right = new Node(NULL,NULL,-1);
                        curNode = curNode->right;
                    }else{
                        curNode = curNode->right;
                    }
                }else{
                    if (curNode->left == NULL){
                        curNode->left = new Node(NULL,NULL,-1);
                        curNode = curNode->left;
                    }else{
                        curNode = curNode->left;
                    }
                }
                temp = temp >> 1;
            }
            curNode->val = inp[idx];
            if (parent->right == NULL){
                parent->right = new Node(NULL,NULL,parent->val);
            }
            if (parent->left == NULL){
                parent->left = new Node(NULL,NULL,parent->val);
            }
            curNode=root;
        }
    }
    cleanup(root);
    long total = 0;
    countNodes(root,&total);
    cout << total << endl;
}
void mr(){
   int size;
   cin >> size;
   size = pow(2,size);
    vector<unsigned> inp;
    int temp;
    for (int idx = 0; idx < size;idx++){
       cin >> temp;
       inp.push_back(temp); 
    }
    sol(inp);
}
int main(){
    mr();
    return 0;
}