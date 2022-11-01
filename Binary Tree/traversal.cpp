#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    TreeNode *left;
    TreeNode *right;
    int val;
    TreeNode()
    {
        left = right = nullptr;
    }
    TreeNode(int x)
    {
        left = right = nullptr;
        val = x;
    }
};
// Recursive Traversal
class RecursiveTraversal
{
public:
    void preOrder(TreeNode *root)
    {
        if (root)
        {
            cout << root->val << " ";
            preOrder(root->left);
            preOrder(root->right);
        }
    }
    void Inorder(TreeNode *root)
    {
        if (root)
        {
            Inorder(root->left);
            cout << root->val << endl;
            Inorder(root->right);
        }
    }
    void postOrder(TreeNode *root)
    {
        if (root)
        {
            postOrder(root->left);
            postOrder(root->right);
            cout << root->val << endl;
        }
    }
};

class IterativeSolution{
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root)return ans;
        stack<TreeNode*>st;
        st.push(root);
        
        while(!st.empty()){
            auto node = st.top();
            ans.push_back(node->val);
            st.pop();
            if(node->right)st.push(node->right);
            if(node->left)st.push(node->left);
        }
        return ans;
    }

    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*>st;
        vector<int> ans;
        st.push(root);
        while(!st.empty()){
            if(root){
                st.push(root);
                root = root->left;
            }
            else{
                root = st.top();
                st.pop();
                if(st.empty())return ans;
                ans.push_back(root->val);
                root = root->right;
            }
        }
        return ans;
    }
    
    
};

int main()
{
    return 0;
}