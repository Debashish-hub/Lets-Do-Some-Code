// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        // Write Your Code here
        sort(candies, candies+N);
        int i = 0, j = N-1 , minres = 0, maxres = 0;
        vector<int> ans;
        while(i <= j){
            minres += candies[i];
            j -= K;
            i++;
        }
        ans.push_back(minres);
        i = 0, j = N-1;
        while(i <= j){
            maxres += candies[j];
            j--;
            i += K;
        }
        ans.push_back(maxres);
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}  // } Driver Code Ends