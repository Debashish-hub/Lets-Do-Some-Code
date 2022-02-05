// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    
    public:
    int transfigure (string A, string B)
    {
    	// Your code goes here
    	int l1 = A.length();
    	int l2 = B.length();
    	if(l1 != l2){
    	    return -1;
    	}
    	int i,j, r=0;
    	int c[256];
    	memset(c, 0, sizeof(c)); 
    	for(i=0;i<l2;i++){
    	    c[A[i]]++;
    	}
    	for(i=0;i<l2;i++){
    	    c[B[i]]--;
    	}
    	for(i=0;i<256;i++){
    	    if(c[i])
    	        return -1;
    	}
    	i = l1-1;
    	j = l2-1;
    	while(i >= 0){
    	    if(A.at(i) != B.at(j))
    	        r++;
    	    else
    	        j--;
    	    i--;
    	}
    	return r;
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
        Solution obj;
        cout << obj.transfigure (A, B) << endl;
    }
}  // } Driver Code Ends