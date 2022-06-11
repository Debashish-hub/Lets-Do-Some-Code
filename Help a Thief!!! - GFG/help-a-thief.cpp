// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int maxCoins(int A[], int B[], int T, int N) {
        // code here
        multimap<int,int> mt;
        
        for(int i=0;i<N;i++)
            mt.insert(pair<int,int> (B[i],A[i]));
        
        int s=0;
        
        for(auto it=mt.rbegin();it!=mt.rend();it++)
        {
            if(T>it->second)
            {
                s+=it->second*it->first;
                T-=it->second;
            }
            else
            {
                s+=it->first*T;
                break;
            }
        }
        return s;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int T,N;
        cin>>T>>N;
        
        int A[N], B[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];
        for(int i=0; i<N; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.maxCoins(A,B,T,N) << endl;
    }
    return 0;
}  // } Driver Code Ends