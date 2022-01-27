// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int solve(int n)
    {
        if(n<=1)
        {
            return 1;
        }
        int x=(2*((2*n)-1)*solve(n-1))/(n+1);
        return x;
    }
 
    int count(int N){
        // code here
        int x;
        x=solve(N/2);
        return x;
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
        cin>>N;
        Solution ob;
        cout << ob.count(N) << endl;
    }
    return 0; 
}  // } Driver Code Ends