// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    int count(int N, vector<int> A,int X)
    {
        // code here
        int ans = N;//worstcase change all bits of all nos to 1
        int mask = 0;
        for(int i=30; i>=0; i--){
            if((X>>i)&1){
                mask ^= (1<<i);//these ones are compulsory to make atleast equal to X
                continue;
            }
            int alternate_mask = (mask^(1<<i));
            //this alternate_mask is greater than X
            int cnt = 0;
            for(int j=0; j<N; j++){
                if((A[j]&alternate_mask) != alternate_mask){
                    cnt += 1;//this no bit positions are to be changed
                }
            }
            ans = min(ans,cnt);
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int N,X;
        cin>>N>>X;
        vector<int> A(N);
        for(auto &i:A)
            cin>>i;
        Solution obj;
        int ans = obj.count(N, A, X);
        cout<<ans<<endl;
    }
}  // } Driver Code Ends