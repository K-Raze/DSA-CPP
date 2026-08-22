/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int ans=0;

    int solve(TreeNode* curr)
    {
        if(!curr)
            return 0;
        int val=curr->val-1;
        val+=solve(curr->left);
        val+=solve(curr->right);
        ans+=abs(val);
        return val;
    }

    int distributeCoins(TreeNode* root) {
        solve(root);
        return ans;
    }
};