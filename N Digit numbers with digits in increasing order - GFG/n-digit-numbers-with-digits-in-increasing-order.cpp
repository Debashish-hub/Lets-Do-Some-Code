// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    void rec(int v, int N, int acc, vector<int> &ret)
    {
    	if (N == 1)
    	{
    		ret.push_back(acc);
    	}
    	else
    	{
    		for (int d = v + 1; d <= 9; ++d)
    			rec(d, N - 1, acc * 10 + d, ret);
    	}
    }
    
    vector<int> increasingNumbers(int N)
    {
    	vector<int> ret;
    	
    	for (int v = (N > 1); v <= 9; ++v)
    		rec(v, N, v, ret);
    	
    	return ret;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        vector<int> ans = ob.increasingNumbers(N);
        for(auto num : ans){
            cout<< num <<" ";
        }
        cout<<endl;
        
    }
    return 0;
}  // } Driver Code Ends