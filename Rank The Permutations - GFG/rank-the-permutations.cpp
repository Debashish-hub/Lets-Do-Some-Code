// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    long factorial(int n) {
        long fact = 1;
        for (int i = 2; i <= n; i++) {
            fact = fact * i;
        }
        return fact;
    }
    long long findRank(string S) {
        //code here
        int n = S.length(), count ;
        long ans = 0;
        for(int i=0; i<n; i++){
            count = 0;
            for(int j=i+1; j<n; j++){
                if((int)S[i]>(int)S[j]){
                    count++;
                }
            }
            ans += factorial(n-i-1)*count;
        }
        return ans+1;
    }
};

// { Driver Code Starts.
int main(){
    int T;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        Solution obj;
        long long ans = obj.findRank(s);
        cout<<ans<<endl;
    }
}  // } Driver Code Ends