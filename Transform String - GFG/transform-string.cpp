// { Driver Code Starts
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    int transform (string A, string B)
    {
        //code here.
        int i=A.size()-1;
       int j=B.size()-1;
       if(i!=j)
       return -1;
       map<char, int> m1;
       map<char, int> m2;
       for(int k=0; k<=i; k++)
       {
           m1[A[k]]++;
           m2[B[k]]++;
       }
       if(m1!=m2)
       return -1;
       int ans=0;
       while(i>=0 && j>=0)
       {
           if(A[i]==B[j])
           {
               i--;
               j--;
           }
           else
           {
               while(A[i]!=B[j] && i>=0 && j>=0)
               {
                   i--;
                   ans++;
               }
           }
       }
       return ans;
    }
};


// { Driver Code Starts.

int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution ob;
        cout <<ob.transform (A, B) << endl;
    }
}  // } Driver Code Ends