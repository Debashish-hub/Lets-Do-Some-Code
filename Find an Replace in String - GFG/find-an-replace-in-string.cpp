// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    string findAndReplace(string S ,int Q, int index[], string sources[], string targets[]) {
        // code here
        int i=0,j=0;
        string ans="";
        while(i<S.size())
        {
            if(index[j]==i)
            {
                int len=sources[j].size();
                string str="";
                for(int k=index[j];k<index[j]+len;k++)
                {
                    str+=S[k];
                }
                if(str==sources[j])
                {
                    ans+=targets[j];
                    i+=len;
                }
                else
                {
                    ans.push_back(S[i]);
                    i++;
                }
                ++j;
            }
            else
            {
                ans.push_back(S[i]);
                i++;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        
        int Q;
        cin>>Q;
        int index[Q];
        string sources[Q], targets[Q];
        
        for(int i=0; i<Q; i++)
            cin>>index[i];
        for(int i=0; i<Q; i++)
            cin>>sources[i];
        for(int i=0; i<Q; i++)
            cin>>targets[i];

        Solution ob;
        cout<<ob.findAndReplace(S,Q,index,sources,targets)<<endl;
    }
    return 0;
}  // } Driver Code Ends