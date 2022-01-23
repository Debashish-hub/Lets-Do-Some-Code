// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
  public:
    string arrangeString(string str)
    {
        //code here.
        map<char, int>mp;
       int sum=0;
       for(int i=0; i<=str.size()-1; i++){
           if(str[i]<'A'){
               int x = str[i]-'0';
               sum += x;
           }
           if(str[i]>='A'){
               mp[str[i]]++;
           }
       }
       string s="";
       for(auto pr:mp){
           while(pr.second--)
          { s+=pr.first;}
       }
       // s+=sum;
       if(sum!=0){
       s += to_string(sum);}
       return s;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout <<ob.arrangeString(s) << endl;
    }
return 0;
}

  // } Driver Code Ends