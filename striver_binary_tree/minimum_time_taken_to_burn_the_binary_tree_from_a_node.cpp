// minimum time taken to burn the binary tree from a node

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
    public:
        map<TreeNode*, TreeNode*> p;
        void parent(TreeNode* root){
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

        int timeToBurn(TreeNode*root){
            if(!root)return 0;
            queue<TreeNode*> q;
            q.push(root);
            map<TreeNode*, bool>visited;
            visited[root] = true;
            int maxi = 0;
            while(!q.empty()){
                int size=q.size();
                while(size--){
                    auto *node = q.front();
                    q.pop();
                    int time = 0;
                    if(node->left and !visited[node->left]){
                        q.push(node->left);
                        visited[node->left] = true;
                        time = 1;
                    }
                    if(node->right and !visited[node->right]){
                        q.push(node->right);
                        visited[node->right] = true;
                        time = 1;
                    }
                    if(p.find(node)!=p.end() and !visited[p[node]]){
                        q.push(p[node]);
                        visited[p[node]] = true;
                        time = 1;
                    }
                    if(time){
                        maxi++;
                    }
                }
            }
            return maxi;

        }
};


int main(){
    return 0;
}
