//  Children Sum Property
#include<bits/stdc++.h>
using namespace std;
// Construct Binary Tree from String with Bracket Representation

struct TreeNode{
    TreeNode* left;
    TreeNode* right;
    int data;
    TreeNode(){
        left = right = nullptr;
    }
    TreeNode(int x){
        left = right = nullptr;
        data = x;
    }
};

class Solution{
    void changeTree(TreeNode*root) {
    // Write your code here.
    if(!root)return ;
    int child = 0;
    if(root->left)child+=root->left->data;
    if(root->right)child+=root->right->data;
    if(child>=root->data)root->data = child;
    else{
        if(root->left)root->left->data = root->data;
        if(root->right)root->right->data = root->data;
    }
    changeTree(root->left);
    changeTree(root->right);
    child = 0;
    if(root->left)child+=root->left->data;
    if(root->right)child+=root->right->data;
    if(root->left or root->right)root->data = child;
    
}
};


int main(){
    return 0;
}