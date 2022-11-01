// Maximum sum of TreeNodes in Binary tree such that no two are adjacent

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
    static int MaximumSum(TreeNode* root){
        if(!root)return 0;
        int notTo = 0;
        int to = root->val;
        if(root->left){
            to+=MaximumSum(root->left->left);
            to+=MaximumSum(root->left->right);
        }
        if(root->right){
            to+=MaximumSum(root->right->left);
            to+=MaximumSum(root->right->right);
        }
        notTo = MaximumSum(root->left) + MaximumSum(root->right);
        return max(to, notTo);
    }
};


// int main()
// {
//     TreeNode* root = new TreeNode(1);
//     root->left = new TreeNode(2);
//     root->right = new TreeNode(3);
//     root->right->left = new TreeNode(4);
//     root->right->right = new TreeNode(5);
//     root->left->left = new TreeNode(1);
 
//     cout << Solution().MaximumSum(root) << endl;
//     return 0;
// }
int main()
{
    TreeNode *root= new TreeNode(10);
    root->left= new TreeNode(1);
    root->left->left= new TreeNode(2);
    root->left->left->left= new TreeNode(1);
    root->left->right= new TreeNode(3);
    root->left->right->left= new TreeNode(4);
    root->left->right->right= new TreeNode(5);
    cout << Solution().MaximumSum(root)<<endl;
    return 0;
}





