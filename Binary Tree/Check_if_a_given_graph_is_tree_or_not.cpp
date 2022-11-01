// Check if a given graph is tree or not

#include<bits/stdc++.h>
using namespace std;
// Approach 1: we would not be going with this approach
// Apporach 2: we have to prove that there in no cycle and graph has exactly n-1 edges
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

int iscycle(vector<int>&mp){
    
}

int main(){
    return 0;
}