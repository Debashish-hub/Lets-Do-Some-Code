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
    vector<double> averageOfLevels(TreeNode* root) {
        
        // Base Case
        if(root == NULL){
            return {};
        }
        
        // Initializaton
        vector<double> ans;
        queue<TreeNode* > q;
        TreeNode* curr;
        q.push(root);
        q.push(NULL);
        double sum = 0;
        int count=0;
        
        // Level order traversal
        while(q.size() > 1){
            curr = q.front();
            q.pop();
            if(curr == NULL){
                q.push(NULL);
                ans.push_back(sum/count);
                sum = 0;
                count = 0;
            }else{
                count++;
                sum += (double)curr->val;
                if(curr->right){
                    q.push(curr->right);
                }
                if(curr->left){
                    q.push(curr->left);
                }
            }
        }
        ans.push_back(sum/count);
        
        return ans;
    }
};