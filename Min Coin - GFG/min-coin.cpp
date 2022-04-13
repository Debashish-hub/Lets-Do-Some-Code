// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int MinCoin(vector<int>nums, int amount)
	{
	    // Code here
	     int n = nums.size();
   
       vector<int > prev(amount + 1, 1e9);
       prev[0] = 0;
        
       for(int i = 1; i <= n; ++i){
           vector<int > curr(amount + 1, 1e9);
           curr[0] = 0;
           for(int j = 1; j <= amount; ++j){
               int ans = 1e9;
               if(nums[i - 1] <= j)
                    ans = min(ans, 1 + curr[j - nums[i - 1]]);
                   
               ans = min(ans, prev[j]);
               
               curr[j] = ans;
           }
           
           prev = curr;
       }
       
       int ans = prev[amount];
       if(ans == 1e9)
        return -1;
        
       return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, amount;
		cin >> n >> amount;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.MinCoin(nums, amount);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends