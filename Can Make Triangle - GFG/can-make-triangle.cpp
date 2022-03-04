// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<int> canMakeTriangle(vector<int> arr, int N){
        // code here
        vector<int> v(N-2);
       
       for(int i = 1 ; i<N-1 ; i++){
           
           bool flag = true;
           
           if(arr[i-1]+arr[i]<=arr[i+1]){
               v[i-1] = 0;
               flag = false;
           }
           
           else if(arr[i+1]+arr[i]<=arr[i-1]){
               v[i-1] = 0;
               flag = false;
           }
           
           else if(arr[i-1]+arr[i+1]<=arr[i]){
               v[i-1] = 0;
               flag = false;
           }
           
           if(flag==true){
               v[i-1] = 1;
           }
       }
       
       return v;
    }
}; 

// { Driver Code Starts.
int main() 
{ 
    int t;cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        vector<int> A(N);
        for(int i=0;i<N;i++)
            cin>>A[i];
        Solution ob;
        auto ans = ob.canMakeTriangle(A, N);
        for(int i=0;i<ans.size();i++)
            cout << ans[i] << " ";
        cout << endl;
        
    }

    return 0; 
}   // } Driver Code Ends