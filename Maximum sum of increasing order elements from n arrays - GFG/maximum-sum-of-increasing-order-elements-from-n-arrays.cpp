// { Driver Code Starts
// CPP program to find maximum sum
// by selecting a element from n arrays
#include<bits/stdc++.h>

using namespace std;

// To calculate maximum sum by
// selecting element from each array
int maximumSum( int n,int m, vector<vector<int>> &a);



// Driver program to test maximumSum
int main() {
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        vector<vector<int>> arr(n, vector<int>(m,0));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            cin>>arr[i][j];
            
        cout << maximumSum(n,m,arr)<<endl;
    
    }
    return 0;

}
// } Driver Code Ends


int maximumSum( int n,int m, vector<vector<int>> &a) {

    // Complete the function
    int sum = 0;
   int i = n-1;
   int prevMax = INT_MAX;
   
   while(i>=0){
       int mx = INT_MIN;
       for(int j=m-1; j>=0; j--){
           if(a[i][j] > mx && a[i][j] < prevMax){
               mx = a[i][j];
           }
       }
       
       if(mx == INT_MIN) return (0);
       sum += mx;
       prevMax = mx;
       i--;
   }
   
   return (sum);
}