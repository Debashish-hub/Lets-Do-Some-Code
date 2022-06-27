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
    bool bst(TreeNode* node, TreeNode* min, TreeNode* max) {
        if (node == NULL) {
            return true;
        }
        
        if ((min && node->val <= min->val) || (max && node->val >= max->val)) {
            return false;
        }

        return bst(node->left, min, node) && bst(node->right, node, max);
    }

    bool isValidBST(TreeNode* root) {
        return bst(root, NULL, NULL);
    }
};