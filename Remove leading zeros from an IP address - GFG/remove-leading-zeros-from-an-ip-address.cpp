// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
  public:
    string newIPAdd (string s)
    {
        //code here.
        stringstream ss(s);
       string temp{};
       string token;
       while(getline(ss,token,'.')){
           bool flag = false;
           string t{};
           for(char ch: token){
               if(!flag){
                   if(ch == '0') continue;
                   else{
                       flag = true;
                       t += ch;
                   }
               }
               else t += ch;
           }
           if(t.size()) temp += t;
           else temp += '0';
           temp += '.';
       }
       string ans{};
       for(int i = 0; i < temp.length() - 1; i++)
           ans += temp[i];
       
       return (ans);
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.newIPAdd (s) << endl;
    }
}

  // } Driver Code Ends