// { Driver Code Starts
// C++ program to find all distinct palindrome sub-strings
// of a given string
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
  public:
    int palindromeSubStrs(string s) {
        // code here
        unordered_map<string,int> m1,m2;
        for(int i=0;i<s.size();i++){
            int j=i-1,k=i+1;
            string t={s[i]};
            m1[t]++;
            while(j>=0&&k<s.size()){
                if(s[j]==s[k])t.push_back(s[j]),j--,k++,m1[t]++;
                else break;
            }
        }
        for(int i=0;i<s.size();i++){
            int j=i,k=i+1;
            string t;
            while(j>=0&&k<s.size()){
                if(s[j]==s[k])t.push_back(s[j]),j--,k++,m2[t]++;
                else break;
            }
        }
        return m1.size()+m2.size();
    }
};

// { Driver Code Starts.

// Driver program
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.palindromeSubStrs(str) << endl;
    }
    return 0;
}
  // } Driver Code Ends