//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(string &a, string &b,int i , int j,vector<vector<int>>&dp)
    {
        if(i==a.size()||j==b.size())
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(a[i]==b[j])
            dp[i][j] = 1 + solve(a,b,i+1,j+1,dp);
        else
            dp[i][j] = max(solve(a,b,i+1,j,dp),solve(a,b,i,j+1,dp));
        return dp[i][j];
    }
    int lcs(string &s1, string &s2) {
        // code here
        int n = s1.length(),m = s2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(s1,s2,0,0,dp);
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2; // Take both the strings as input
        Solution ob;
        cout << ob.lcs(s1, s2) << endl; // Call the lcs function
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends