// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends

class Solution{
    public:
    string removeConsecutiveCharacter(string s)
    {
        // code here.
        string temp = "";
        for(int i=0;i<s.size();i++){
           if(temp.length() == 0){
               temp.push_back(s[i]);
            }else{
                if(s[i] == s[i-1]){
                       continue;
                }else{
                    temp.push_back(s[i]);
                }
            }
        }
       return temp;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.removeConsecutiveCharacter(s)<<endl;
    }
} 



  // } Driver Code Ends