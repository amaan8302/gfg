//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to count number of ways to reach the nth stair.
    int solve(int n,vector<int>&dp)
    {
        if (n <= 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 2;
        
        if (dp[n] != -1) return dp[n];
        int one = solve(n-1, dp);
        int two = solve(n-2, dp);
        return dp[n] = one + two;
    }
    int countWays(int n) {
        // your code here
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};


//{ Driver Code Starts.
int main() {
    // taking total testcases
    int t;
    cin >> t;
    while (t--) {
        // taking stair count
        int m;
        cin >> m;
        Solution ob;
        cout << ob.countWays(m) << endl; // Print the output from our pre computed array

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends