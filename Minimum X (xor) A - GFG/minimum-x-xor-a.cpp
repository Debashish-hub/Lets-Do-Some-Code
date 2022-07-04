// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  static int LSB(int x) {
        return x & -x;
    }
  static int countBits(int x) {
        int n{};
        while (x) {
            ++n;
            x &= ~LSB(x);
        }
        return n;
    }
    int minVal(int a, int b) {
        // code here
        int na = countBits(a), nb = countBits(b);
        for (int i = 0; i < na - nb; ++i) {
            a &= ~LSB(a); // Strip off excess least-significant ones
        }
        for (int i = 0; i < nb - na; ++i) {
            a |= LSB(~a); // Flip the least-significant zeros
        }
        return a;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}  // } Driver Code Ends