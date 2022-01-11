// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    void clonestack(stack<int> st, stack<int>& cloned)
    {
        //code here
        while(!st.empty()){
            int topElement = st.top(); st.pop();
            int cnt = 0;
            // now pop all the cloned elements and put them in stack st, now push topElement to cloned stack
            while(!cloned.empty()){
                cnt += 1;
                int x = cloned.top(); cloned.pop();
                st.push(x);
            }
            cloned.push(topElement);
            // now push previouly stored elements of cloned stack from stack st
            while(cnt>0){
                cloned.push(st.top());
                st.pop();
                cnt -= 1;
            }
        }
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int arr[N];
        stack<int> st;
        vector<int> copy;
        for(int i = 0; i < N; i++){
            cin >> arr[i];
            st.push(arr[i]);
            copy.push_back(arr[i]);
        }
        
        reverse(copy.begin(), copy.end());
        
        Solution ob;
        stack<int> cloned;
        ob.clonestack(st,cloned);
        vector<int> check;
        while(cloned.size())
        {
            check.push_back(cloned.top());
            cloned.pop();
        }
        
        int flag = 0;
        if(check!=copy)
            flag = 1;
        
        cout<<1-flag<<endl;
    }
    return 0; 
} 
  // } Driver Code Ends