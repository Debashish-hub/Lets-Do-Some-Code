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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int, map<int, multiset<int>>> m;
        queue<pair<TreeNode* , pair<int, int>>> q;
        
        q.push({root,{0,0}});
        
        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            
            TreeNode* node = p.first;
            int i = p.second.first;
            int j = p.second.second;
            
            m[i][j].insert(node->val);
            
            if(node->left) {
                q.push({node->left, {i-1, j+1}});
            }
            if(node->right) {
                q.push({node->right, {i+1, j+1}});
            }
        }
        
        for(auto it:m) {
            vector<int> col;
            for(auto c: it.second) {
                col.insert(col.end(), c.second.begin(), c.second.end());
            }
            ans.push_back(col);
        }
        return ans;

    }
};