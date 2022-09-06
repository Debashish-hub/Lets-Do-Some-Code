/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>>ans;
    void solve(Node* root,int dep)
    {
        if(root==NULL)return;
        while(ans.size()<=dep)ans.push_back({});
        ans[dep].push_back(root->val);
        for(int i=0;i<root->children.size();i++)
        {
            solve(root->children[i],dep+1);
        }       
    }
    vector<vector<int>> levelOrder(Node* root) 
    {
        solve(root,0);
        return ans;
    }
};