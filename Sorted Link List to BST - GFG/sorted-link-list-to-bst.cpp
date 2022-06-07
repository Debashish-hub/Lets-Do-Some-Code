// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct LNode
{
    int data;
    struct LNode* next;
    
    LNode(int x){
        data = x;
        next = NULL;
    }
};

struct TNode  
{  
    
    int data;  
    struct TNode* left;  
    struct TNode* right; 
    TNode(int x)
    {
        data=x;
        left=right=NULL;
    }
}; 

void preOrder(TNode* node)  
{  
    if (node == NULL)  
        return;  
    cout<<node->data<<" ";  
    preOrder(node->left);  
    preOrder(node->right);  
} 


 // } Driver Code Ends
//User function Template for C++


//User function Template for C++

/* 
//Linked List
struct LNode
{
    int data;
    struct LNode* next;
    
    LNode(int x){
        data = x;
        next = NULL;
    }
};

//Tree
struct TNode  
{  
    
    int data;  
    struct TNode* left;  
    struct TNode* right; 
    TNode(int x)
    {
        data=x;
        left=right=NULL;
    }
}; */
class Solution{
  public:
    TNode* sortedListToBSTRecur(LNode **head_ref, int n)
    {
        /* Base Case */
        if (n <= 0)
            return NULL;
        TNode *left = sortedListToBSTRecur(head_ref, n/2);
        TNode *root = new TNode((*head_ref)->data);
        root->left = left;
        *head_ref = (*head_ref)->next;
        root->right = sortedListToBSTRecur(head_ref, n - n / 2 - 1);
     
        return root;
    }
    int countLNodes(LNode *head)
    {
        int count = 0;
        LNode *temp = head;
        while(temp)
        {
            temp = temp->next;
            count++;
        }
        return count;
    }
    TNode* sortedListToBST(LNode *head) {
        //code here
        int n = countLNodes(head);
        return sortedListToBSTRecur(&head, n);
    }
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        int data;
        cin>>data;
        LNode *head = new LNode(data);
        LNode *tail = head;
        for (int i = 0; i < n-1; ++i)
        {
            cin>>data;
            tail->next = new LNode(data);
            tail = tail->next;
        }
        Solution ob;
        TNode* Thead = ob.sortedListToBST(head);
        preOrder(Thead);
        cout<<"\n";
        
    }
    return 0;
}
  // } Driver Code Ends