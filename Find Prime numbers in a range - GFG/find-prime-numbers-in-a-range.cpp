// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

bool primes[1000001];
bool flag = 0;

class Solution {
   
   void seive(){
   primes[1]=true;
   for(int i=2;i*i<=1000000;i++)
       if(!primes[i]){
           for(int j=i*i;j<=1000000;j+=i)
               primes[j]=true;
       }
   }
   
 public:
   vector<int> primeRange(int M, int N) {
       
       if(flag==0){
           memset(primes, 0, sizeof(primes));
           seive();
           flag=1;
       }
       
       vector<int> ans;
       
       for(int i=M;i<=N;i++)
           if(!primes[i])
               ans.push_back(i);
       
       return ans;
   }
};
// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, K;
        cin >> M >> N;
        Solution ob;
        vector<int> ans = ob.primeRange(M, N);
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
}  // } Driver Code Ends