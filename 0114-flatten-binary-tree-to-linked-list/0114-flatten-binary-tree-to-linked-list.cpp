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

    TreeNode* meow;

    void make(TreeNode* curr)
    {
        meow->right=new TreeNode(curr->val);
        meow=meow->right;
        if(curr->left)
            make(curr->left);
        if(curr->right)
            make(curr->right);
    }

    void flatten(TreeNode* root) {
        if(!root)
            return;
        TreeNode* dummy = new TreeNode();
        meow = dummy;
        make(root);
        *root = *dummy->right; 
    }
};