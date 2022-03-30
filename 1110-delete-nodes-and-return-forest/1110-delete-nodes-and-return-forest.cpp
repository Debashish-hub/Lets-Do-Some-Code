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
    vector<TreeNode*> ans;
    void solve(TreeNode* &root, set<int> mp){
        if(!root){
            return;
        }
        solve(root->left, mp);
        solve(root->right, mp);
        if(mp.find(root->val) != mp.end()){
            if(root->left){
                ans.push_back(root->left);
            }
            if(root->right){
                ans.push_back(root->right);
            }
            root = NULL;
            delete root;
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_del) {
        set<int> mp;
        for(int i=0; i<to_del.size(); i++){
            mp.insert(to_del[i]);
        }
        solve(root, mp);
        if(root){
            ans.push_back(root);
        }
        return ans;
    }
};