// Count all subsequences having product less than K

#include<bits/stdc++.h>
using namespace std;

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

void traversal(TreeNode* root, TreeNode* &prev){
    
    if(root){
        traversal(root->left, prev);
        if(!prev)cout<<"prev==null"<<endl;
        else cout<<prev->data<<endl;
        prev = root;
        traversal(root->right, prev);
    }
}



int main(){
    TreeNode*root = new TreeNode(10);
    TreeNode* leaf1 = new TreeNode(11);
    TreeNode* leaf2 = new TreeNode(12);
    TreeNode* leaf3 = new  TreeNode(13);
    TreeNode* leaf4 = new  TreeNode(14);
    TreeNode* leaf5 = new  TreeNode(15);
    TreeNode* leaf6 = new  TreeNode(16);
    root->left = leaf1;
    root->right = leaf2;
    leaf1->left = leaf3;
    leaf1->right = leaf4;
    leaf2->left = leaf5;
    leaf2->right = leaf6;
    TreeNode * prev = nullptr;
    traversal(root, prev);
    return 0;
}