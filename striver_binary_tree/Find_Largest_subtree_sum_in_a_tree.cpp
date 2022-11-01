// Find Largest subtree sum in a tree

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

class Solution
{
public:
    static int findLargestSubtreeSum(TreeNode *root, int &maxsum)
    {
        if (!root)
            return 0;
        auto left = findLargestSubtreeSum(root->left, maxsum);
        auto right = findLargestSubtreeSum(root->right, maxsum);
        int currsum = left + right + root->val;
        maxsum = max(maxsum, currsum);
        return currsum;
    }
};

int main()
{
    int maxsum = INT_MIN;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(-2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(-6);
    root->right->right = new TreeNode(2);
    int ans = Solution().findLargestSubtreeSum(root, maxsum);
    cout << ans <<endl;
    return 0;
}