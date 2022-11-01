// Print all the Nodes at a distance of K in Binary Tree

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

class Solution {
public:
    map<TreeNode*, TreeNode*> p;
    void parent(TreeNode*root){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto *node = q.front();
            q.pop();
            if(node->left){
                p[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                p[node->right] = node;
                q.push(node->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!root or !target)return {};
        parent(root);
        queue<TreeNode*> q;
        map<TreeNode*, bool> visited;
        q.push(target);
        visited[target] = true;
        int currlevel = 0;
        while(!q.empty()){
            int size = q.size();
            if(currlevel++==k)break;
            while(size--){
                auto *node = q.front();
                q.pop();
                if(node->left and !visited[node->left]){
                    visited[node->left] = true;
                    q.push(node->left);
                }
                if(node->right and !visited[node->right]){
                    visited[node->right] = true;
                    q.push(node->right);
                }
                if(p.find(node)!=p.end() and !visited[p[node]]){
                    visited[p[node]] = true;
                    q.push(p[node]);
                }
            }
        }
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
        
    }
};
int main(){
    return 0;
}