// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string s) {
        // Code here
        int n = s.size();
        int zeroIdx =-1, oneIdx =-1, twoIdx = -1, i = 0;
        int ans = INT_MAX;
        while(i<n){
            if(s[i] == '0'){
                zeroIdx = i;
            }
            else if(s[i] == '1'){
                oneIdx = i;
            }
            else{
                twoIdx = i;
            }
            
            if(zeroIdx != -1 && twoIdx != -1 && oneIdx != -1){
                int arr[] = {zeroIdx,oneIdx,twoIdx};
                int sz = *max_element(arr,arr+3) - *min_element(arr,arr+3)+1;
                ans = min(ans,sz);
            }
            
            
            i += 1;
        }
        return (ans==INT_MAX?-1:ans);

    }
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}  // } Driver Code Ends