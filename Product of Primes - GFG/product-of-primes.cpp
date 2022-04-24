// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    #define ll long long
    const ll mod = 1e9+7;
    bool prime(ll n){
        for(ll i = 2 ; i*i <= n ;i++){
            if(n % i == 0) return 0;
        }
        return 1;
    }
    long long primeProduct(long long L, long long R){
        ll ans = 1L;
        for(ll i=L ; i<= R ; i++){
            if(prime(i)){
                ans*= i;
                ans %= mod;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long L, R;
        cin>>L>>R;
        
        Solution ob;
        cout<<ob.primeProduct(L, R)<<"\n";
    }
    return 0;
}  // } Driver Code Ends