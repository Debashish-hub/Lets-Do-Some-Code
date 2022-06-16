// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here   
        unordered_map<char,int>m;
       for(int i=0;i<str.size();i++){
           m[str[i]]++;
       }
       unordered_map<char,int>mp;
       int k=m.size();
       int mx=INT_MAX;
       int i=0;
       int j=0;
       while(j<str.size()){
           mp[str[j]]++;
           if(mp.size()<k)
             j++;
             else if(mp.size()==k){
                 mx=min(mx,j-i+1);
                 while(mp.size()==k){
                     mx=min(mx,j-i+1);
                     mp[str[i]]--;
                     if(mp[str[i]]==0)
                     mp.erase(str[i]);
                     i++;
                 }
                 j++;
             }
             
       }
       return mx;
    }
};

// { Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}  // } Driver Code Ends