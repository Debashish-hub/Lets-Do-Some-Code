// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

int maxProfit(vector<int>&price){
    //Write your code here..
    int wallet1= INT_MAX, wallet2= INT_MAX;
   int profit1=0,profit2=0;
     for (int i=0; i< price.size(); i++){
          
           wallet1= min (wallet1, price[i]);
           
           profit1= max (profit1, price[i]-wallet1);
           
           wallet2= min (wallet2, price[i] - profit1);
           
           profit2= max (profit2, price[i] - wallet2);
      }
      return profit2;
}

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        cout<<maxProfit(price)<<endl;
    }

}
  // } Driver Code Ends