// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


 // } Driver Code Ends
/*
// node structure:

struct Node
{
    int data;
    Node* left;
    Node* right;
};

*/

class Solution{
public:
    Node * markParent(Node * root , unordered_map<Node*,Node*>&parent , int target){
       
       queue<Node*> q;
       q.push(root);
       Node * res;
       
       while(!q.empty()){
           Node * temp = q.front();
           q.pop();
           
           if(temp->data == target){
               res = temp;
           }
           
           if(temp->left){
               parent[temp->left] = temp;
               q.push(temp->left);
           }
           
           if(temp->right){
               parent[temp->right] = temp;
               q.push(temp->right);
               
           }
       }
       
       return res;
       
   }

   int sum_at_distK(Node* root, int target, int k)
   {
       // code here
       unordered_map<Node*,Node*> parent;
       Node * res = markParent(root,parent,target);
       
       // for(auto itr = parent.begin() ; itr != parent.end() ; itr++){
       //     cout << itr->first->data << " " << itr->second->data << endl;
       // }
       
       unordered_map<Node*,bool> visited;
       queue<pair<Node* , int>>q;
       pair<Node*,int>p2(res,0);
       q.push(p2);
       
       visited[res] = true;
       // cout << "parent[root]" << " : " << parent[root] << endl;
       int sum = res->data;
       int l = 0;
       
       while(!q.empty()){
           
           pair<Node*,int> p = q.front();
           Node * temp = p.first;
           int l = p.second;
           q.pop();
           if(l+1 <= k){
               if(temp->left && !visited[temp->left]){
                   sum += temp->left->data;
                   pair<Node*,int> p1(temp->left,l+1);
                   q.push(p1);
                   visited[temp->left] = true;
               }
               
               if(temp->right && !visited[temp->right]){
                   sum += temp->right->data;
                   pair<Node*,int> p1(temp->right,l+1);
                   q.push(p1);
                   visited[temp->right] = true;
               }
               // cout << "temp" << " : " << temp->data << endl;
               // cout << "l" << " : " << l << endl; 
               // cout << "parent[temp]" << " : " << parent[temp]->data << endl;
               // cout << "visited[parent[temp]]" << " : " << visited[parent[temp]] << endl;
               
               if(parent[temp] && !visited[parent[temp]]){
                   // if(l == 0 || l == 1 || l == 2){
                       sum += parent[temp]->data;
                       visited[parent[temp]] = true;
                       pair<Node*,int> p1(parent[temp],l+1);
                       q.push(p1);
                   // }
               }
           }
           
       
       }
       
       return sum;
   }
};



// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        
        int target,k;
        cin>> target >> k;
        getchar();
        
        Solution ob;
        cout<< ob.sum_at_distK(root,target,k) << endl;
    }
	return 0;
}

  // } Driver Code Ends