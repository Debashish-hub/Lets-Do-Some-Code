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
    TreeNode* increasingBST(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode *node = root, *prev = NULL, *head = NULL; 
        
        while (stk.size() || node) {
            if (node) {
                stk.push(node); 
                node = node->left; 
            } else {
                node = stk.top(); 
                stk.pop(); 
                if (prev == NULL) {
                    head = prev = node; 
                } else {
                    prev = prev->right = node; 
                }
                node->left = NULL; 
                node = node->right; 
            }
        }
        return head; 
    }
};