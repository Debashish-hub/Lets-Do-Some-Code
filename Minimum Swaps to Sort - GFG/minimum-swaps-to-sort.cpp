// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&arr)
	{
	    // Code here
	    int n = arr.size();
	    vector<pair<int,int>> vec(n);
     
        for(int i=0;i<n;i++){
            vec[i].first=arr[i];
            vec[i].second=i;
        }
     
        sort(vec.begin(),vec.end());
     
        int ans=0,c=0,j;
     
        for(int i=0;i<n;i++){  
            if(vec[i].second==i)
                continue;
            else{
                swap(vec[i].first,vec[vec[i].second].first);
                swap(vec[i].second,vec[vec[i].second].second);
            }
            if(i!=vec[i].second)
                --i;
            ans++;
        }
     
        return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends