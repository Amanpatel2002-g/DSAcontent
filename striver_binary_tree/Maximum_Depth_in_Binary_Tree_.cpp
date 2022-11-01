// Maximum Depth in Binary Tree

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    TreeNode *left;
    TreeNode *right;
    int data;
    TreeNode()
    {
        left = right = nullptr;
    }
    TreeNode(int x)
    {
        left = right = nullptr;
        data = x;
    }
};

class Solution
{
public:
    int RecursiveDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        return 1 + max(RecursiveDepth(root->left), RecursiveDepth(root->right));
    }

    int IterativeDepth(TreeNode*root){
        queue<TreeNode*>q;
        q.push(root);
        int h = 0;
        while(!q.empty()){
            int size = q.size();
            h++;
            while(size--){
                
            }
        }
    }

};

int main()
{
    return 0;
}