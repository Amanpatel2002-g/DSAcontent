// Kth Ancestor of  BinaryTreeNode<int>  in a Binary tree

#include <bits/stdc++.h>
using namespace std;

struct  BinaryTreeNode<int> 
{
     BinaryTreeNode<int>  *left;
     BinaryTreeNode<int>  *right;
    int data;
     BinaryTreeNode<int> ()
    {
        left = right = nullptr;
    }
     BinaryTreeNode<int> (int ans)
    {
        left = right = nullptr;
        data = ans;
    }
};

class Solution
{
public:
     BinaryTreeNode<int> *ans = nullptr;
     BinaryTreeNode<int> * solve( BinaryTreeNode<int> *root, int t, int &k){
         BinaryTreeNode<int>  *temp = nullptr;
        if(!root)return nullptr;
        if((root->data==t) or (temp=solve(root->left, t, k)) or (temp=solve(root->right, t, k))){
            if(k==0){
                ans = root;
                k--;
                return nullptr;
            }
            k--;
            return temp?temp:root;
        }
        return nullptr;
    }

    int findKthAncestor( BinaryTreeNode<int>  *root, int target BinaryTreeNode<int> Val, int k)
    {
        if (!root)
            return -1;
        solve(root, target BinaryTreeNode<int> Val, k);
        if (ans!=nullptr){
            return ans->data;
        }
        return -1;
    }
};

int main()
{
    // Let us create binary tree shown in above diagram
     BinaryTreeNode<int>  *root = new  BinaryTreeNode<int> (1);
    root->left = new  BinaryTreeNode<int> (2);
    root->right = new  BinaryTreeNode<int> (3);
    root->left->left = new  BinaryTreeNode<int> (4);
    root->left->right = new  BinaryTreeNode<int> (5);

    int k = 3;
    int  BinaryTreeNode<int>  = 5;

    // print kth ancestor of given  BinaryTreeNode<int> 
    Solution sol;
    int ans = sol.findKthAncestor(root,  BinaryTreeNode<int> , k);
    cout<<"here we are"<<endl;
    cout<<ans<<endl;
    // check if parent is not NULL, it means
    // there is no Kth ancestor of the nod
    return 0;
}