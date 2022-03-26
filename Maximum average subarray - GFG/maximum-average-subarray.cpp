// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int findMaxAverage(int arr[], int n, int k) {
        // code here
        int p=0,q=k-1,i=0; 
        long double avg=0.0,ma=0.0;
        for(i=0;i<k;i++)
        {
            avg+=arr[i];
        }
        ma=(long double)avg/k;
        for(;i<n;i++)
        {
             avg-=arr[i-k];
             avg+=arr[i];
             if(ma<(long double)avg/k)
             {
               ma=(long double)avg/k;
               p=i-k+1;
               q=i;
             }
             
        }
       return p;  
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxAverage(arr, n, k);
        for (int i = ans; i < ans + k; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends