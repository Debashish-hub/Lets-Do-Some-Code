// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    long long int minSum(int arr[], int n)
    {
        // Your code goes here
        sort(arr,arr+n);
     
         priority_queue<int>pq_even;
         priority_queue<int>pq_odd;
         for(int i=0;i<n;i=i+2){
           pq_even.push(arr[i]);  
         }
          for(int i=1;i<n;i=i+2){
           pq_odd.push(arr[i]);  
         }
         
         long long int num1=0;
         long long int power=1;
         while(!pq_even.empty()){
             num1+=(pq_even.top()*power);
             pq_even.pop();
             power*=10;
         }
         power=1;
         long long int num2=0;
         while(!pq_odd.empty()){
             num2+=(pq_odd.top()*power);
             pq_odd.pop();
             power*=10;
         }
         return num1+num2;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n+1];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.minSum(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends