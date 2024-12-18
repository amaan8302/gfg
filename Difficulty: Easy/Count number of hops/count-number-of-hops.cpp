//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(int i , int n)
    {
        if(i==n)
            return 1;
        if(i>n)
            return 0;
        return solve(i+1,n)+solve(i+2,n)+solve(i+3,n);
    }
    int countWays(int n) {
        return solve(0,n);
    }
};


//{ Driver Code Starts.
int main() {
    // taking testcases
    int t;
    cin >> t;

    while (t--) {
        // taking number of steps in stair
        int n;
        cin >> n;
        Solution ob;
        // calling function countWays()
        cout << ob.countWays(n) << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends