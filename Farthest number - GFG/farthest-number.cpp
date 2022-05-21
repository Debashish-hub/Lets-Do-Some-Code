// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution{   
  public:
    vector<int> farNumber(int n,vector<int> arr){
        //code here
       vector<int> min_array(n);
       vector<int> ans;
       min_array[n-1] = arr[n-1];
       for(int i=n-2;i>=0;i--){
           min_array[i] = min(arr[i],min_array[i+1]);
       }
       
       
       for(int i=0;i<n;i++){
           
           int low = i+1,high= n-1,res = -1;
           
           while(low<=high){
               int mid = (low+high)/2;
               
           // If current element in the min_array
           // is less than a[i] then move right
           if (min_array[mid] < arr[i]) {
               res = mid;
               low = mid + 1;
           }
           else
               high = mid - 1;

           }
           
           ans.push_back(res);
           
       }
       
       return ans;
    }
};

// { Driver Code Starts.
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        vector<int> Arr(N);
        for(int i=0;i<N;i++)
            cin>>Arr[i];
        Solution obj;
        vector<int> answer=obj.farNumber(N,Arr);
        for(auto i:answer)
            cout<<i<<" ";
        cout<<endl;
  }
}  // } Driver Code Ends