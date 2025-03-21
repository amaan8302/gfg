//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    long long nCr(int n, int r) 
    {
        if (r > n) return 0;
        if (r == 0 || r == n) return 1;
        long long res = 1;
        r = min(r, n - r);
        for (int i = 0; i < r; i++) {
            res *= (n - i);
            res /= (i + 1);
        }
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, r;
        cin >> n >> r;

        Solution ob;
        cout << ob.nCr(n, r) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends