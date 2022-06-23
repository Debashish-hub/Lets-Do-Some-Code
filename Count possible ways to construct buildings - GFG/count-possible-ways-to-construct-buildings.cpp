// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int TotalWays(int N)
	{
	    // Code here
	    long pre=2; long cur=3;
       if(N==1){ return 4; }
       if(N==2){ return 9; }
       for(int i=3; i<=N; i++){
           long val=cur;
           cur+=pre;
           cur%=1000000007;
           pre=val;
       }
       return (int)((cur*cur)%1000000007);
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends