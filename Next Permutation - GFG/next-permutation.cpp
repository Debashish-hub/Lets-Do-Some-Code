// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void reverse(vector<int>& arr, int start){
        int i = start, j = arr.size()-1;
        while(i < j){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
    
    vector<int> nextPermutation(int N, vector<int> arr){
        int i = N-2;
        while(i >=0 && arr[i+1] <= arr[i]){
            i--;
        }
        if(i >= 0){
            int j = N-1;
            while(arr[j] <= arr[i]){
                j--;
            }
            swap(arr[i],arr[j]);
        }
        reverse(arr,i+1);
        
        return arr;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends