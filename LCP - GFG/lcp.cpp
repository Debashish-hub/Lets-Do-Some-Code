// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    string LCP(string ar[], int n)
    {
        // code here
        sort(ar,ar+n);
       string t=ar[0];
       for(int i=1;i<n;i++)
       {
          // string lcp=t;
           if(ar[i].find(t)!=-1)
           continue;
           else if(t.find(ar[i])!=-1)
           {
               t=ar[i];
              
           }
           else
           {
               string s;
               for(int j=0;j<min(ar[i].length(),t.length());j++)
               {
                   if(t[j]==ar[i][j])
                   s.push_back(t[j]);
                   else
                   break;
               
               }
               t=s;
           }
           
       }
       if(t.size()>0)
       return t;
       else
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
	        int n;
	        cin>>n;
	        string arr[n];
	        for(int i = 0;i<n;i++)
	            cin>>arr[i];
	        Solution ob;
	        cout<<ob.LCP(arr,n)<<endl;
	    }
	return 0;
}  // } Driver Code Ends