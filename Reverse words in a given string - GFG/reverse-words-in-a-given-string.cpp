// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
        string str="";
        string result="";
        string word;
        for(int i=0;S[i]!='\0';i++){
            if(S[i]=='.'){
                word=S[i]+str;
                str="";
            }
            else{
                str+=S[i];
            }
            result=word+result;
            word="";
        }
        if(str!="") result=str+result;
        return result;
    } 
};

// { Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}  // } Driver Code Ends