// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    string chooseandswap(string s){
        // Code Here
        vector<int>v(26,-1);
      int n=s.size();
      
      for(int i=0;i<n;i++)
      {
          if(v[s[i]-97]==-1)
          v[s[i]-97]=i;
      }
      
      int f=0;
      char a,b;
      for(int i=0;i<n;i++)
      {
          for(char ch='a';ch<s[i];ch++)
          {
              if(v[ch-97]!=-1 and v[ch-97]>i)
              {
                  a=s[i];
                  b=ch;
                  f=1;
                  break;
              }
          }
          
          if(f==1)
          break;
      }
     
     if(f==1)
     {
      for(int i=0;i<n;i++)
      {
          if(s[i]==a)
          s[i]=b;
          
          else if(s[i]==b)
          s[i]=a;
      }
     }
      
      return s;
    }
    
};


// { Driver Code Starts.

int main()
{
    Solution obj;
	int t;
	cin >> t;
	while(t--)
	{	
	    string a;
		cin >> a;
		cout << obj.chooseandswap(a) << endl;
	}
	return 0;
}
  // } Driver Code Ends