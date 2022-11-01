// Print all K Sum paths in a Binary tree

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
    vector<vector<int>>ans_vector;
    int pathsum(TreeNode*root, long long int targetsum, vector<int> &v){
        int ans = 0;
        if(!root)return ans;
        if(root->val==targetsum){
            ans++;
            ans_vector.push_back(v);
        }
        v.push_back(root->val);
        ans+=pathsum(root->left, targetsum-root->val, v);
        ans+=pathsum(root->right, targetsum-root->val, v);
        return ans;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root)return 0;
        vector<int> v;
        return pathSum(root->left, targetSum) + pathsum(root, targetSum, v)+pathSum(root->right, targetSum);
    }
};

int main(){
    return 0;
}