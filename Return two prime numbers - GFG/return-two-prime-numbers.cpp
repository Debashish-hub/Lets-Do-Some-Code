// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

vector<int> primes(10002,1);
int flag=1;

class Solution{
public:


    void sieve(){
        
        flag=!flag ;
        for(int i=2;i*i<10001;i++)
            if(primes[i])
                for(int j=i*i;j<10001;j+=i)
                    primes[j]=0;
                
    }

    vector<int> primeDivision(int N){
        
        if(flag)
            sieve();
            
        for(int i=2;i<=(N/2)+1;i++)
            if(primes[i] && primes[N-i])
                return {i,N-i};
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.primeDivision(N);
        cout<<ans[0]<<" "<<ans[1]<<"\n";
    }
    return 0;
}  // } Driver Code Ends