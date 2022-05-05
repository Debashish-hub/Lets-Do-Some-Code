// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string stringPartition(string S, int a, int b){
        // code here 
         string ans="";
     for(int i=0;i<S.length();i++)
     {
         ans+=S[i];
         if(ans.length()==S.length())
         {
         return "-1";
          }
         if(stoi(ans)%a==0)
         {
             
             string val="";
             int j=i+1;
             while(j<S.length())
             {
                 val+=S[j];
                 j++;
             }
       
           
             if(stoi(val)%b==0)
             {
                 
                 return ans+" "+val;
             }
         }
     }
     return "-1";
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {   
        int a,b;
        string S;
        cin >> S >> a >> b;
        Solution ob;
        cout << ob.stringPartition(S,a,b) << endl;
    }
    return 0; 
}   // } Driver Code Ends