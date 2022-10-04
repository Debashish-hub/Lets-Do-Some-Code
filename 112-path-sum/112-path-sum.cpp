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
    bool sum(TreeNode * root, int t){
        if(root == NULL)
            return false;
        if(root->right == NULL && root->left == NULL)
            return t == root->val;
        return (sum(root->left, t - root->val) || sum(root->right, t - root->val));
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL)
            return false;
        return sum(root ,targetSum);
    }
};