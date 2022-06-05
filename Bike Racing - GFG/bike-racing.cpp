// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isValid(long mid,long H[],long A[],long N,long M,long L){
       long total = 0;
       for(long i = 0; i < N; i++){
           long v = H[i] + A[i]*mid;
           if(v > L){
               total += v;
           }
           if(total >= M) return (true);
       }
       
       return (false);
   }
   
   long buzzTime(long N, long M, long L, long H[], long A[]){
       long s = 0, e = 1e9;
       long ans = 0;
       while(s <= e){
           long mid = s + (e-s)/2;
           if(isValid(mid,H,A,N,M,L)){
               ans = mid;
               e = mid - 1;
           }
           else{
               s = mid + 1;
           }
       }
       return (ans);
   }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long N, M, L;
        cin>>N>>M>>L;
        long H[N], A[N];
        for(long i = 0;i < N;i++) 
            cin>>H[i]>>A[i];
        
        Solution ob;
        cout<<ob.buzzTime(N, M, L, H, A)<<"\n";
    }
    return 0;
}  // } Driver Code Ends