// Construct a Binary Tree from Preorder and Inorder Traversal

#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    TreeNode* left;
    TreeNode* right;
    int val;
    TreeNode(){
        left = right = nullptr;
    }
    TreeNode(int x){
        left = right = nullptr;
        val = x;
    }
};

class Solution{
    TreeNode*solve(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, map<int,int>&mp){
        if(preStart>preEnd or inStart>inEnd){
            return NULL;
        }
        TreeNode * root = new TreeNode(preorder[preStart]);
        int inroot = mp[preorder[preStart]];
        int left = inroot - preStart;
        root->left = solve(preorder, preStart+1, preStart+left, inorder, inStart, inroot, mp);
        root->right = solve(preorder, preStart+left, preEnd, inorder, inroot+1, inEnd, mp);
        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>mp;
        int n = inorder.size();
        for(int i = 0; i<n; i++){
            mp[inorder[i]] = i; 
        }
        return solve(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, mp);
    }
};

int main(){
    return 0;
}