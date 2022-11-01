// Minimum swap required to convert binary tree to binary search tree

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
    TreeNode* makeheaptree(vector<int>&nums, int i){
        if(i>=nums.size())return nullptr;
        TreeNode*root = new TreeNode(nums[i]);
        root->left = makeheaptree(nums, (2*i) +1);
        root->right= makeheaptree(nums, (2*i) + 2);
        return root;
    }
    TreeNode* makeTreefromInorder(vector<int>&nums, int i, int j){
        if(i>j)return nullptr;
        int mid = (i+j)/2;
        TreeNode*node = new TreeNode(nums[mid]);
        if(i<j){
            node->left = makeTreefromInorder(nums, i, mid-1);
            node->right = makeTreefromInorder(nums, mid+1, j);
        }
        return node;
    }
    int swaps(vector<int>&nums,TreeNode*heaptree,TreeNode*inTree){
        
    }
    int minswaps(vector<int> &nums){
        // let me consturct tree
        TreeNode*heaptree = makeheaptree(nums, 0);
        sort(nums.begin(), nums.end());
        TreeNode*inTree = makeTreefromInorder(nums, 0, nums.size()-1);
    }
};

int main(){
    return 0;
}