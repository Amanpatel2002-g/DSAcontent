// Preorder Inorder Postorder Traversals in One Traversal
// you are given the tree and you will have to find the preOrder, inOrder, postOrder
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
        vector<int> preOrder, inOrder, postOrder; 
        void allInOneTraversal(TreeNode*root){
            stack<pair<TreeNode*,int>> st;
            st.push({root, 1});
            while (!st.empty())
            {
                TreeNode*node = st.top().first;
                int * val = &st.top().second;
                if(*val==1){
                    preOrder.push_back(node->val);
                    *val = 2;
                    if(node->left){
                        st.push({node->left, 1});
                    }
                }
                else if(*val==2){
                    inOrder.push_back(node->val);
                    *val = 3;
                    if(node->right){
                        st.push({node->right, 1});
                    }
                }
                else{
                    inOrder.push_back(node->val);
                    st.pop();
                }
            }
            
        }
};


int main(){
    return 0;
}