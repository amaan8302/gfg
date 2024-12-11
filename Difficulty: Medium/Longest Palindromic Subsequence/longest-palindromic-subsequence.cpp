//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int solve(string a , string b, int i , int j , vector<vector<int>>&dp)
    {
        if(i==a.size() || j == b.size())
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(a[i]==b[j])
            dp[i][j] = 1 + solve(a,b,i+1,j+1,dp);
        else
            dp[i][j] = max(solve(a,b,i+1,j,dp),solve(a,b,i,j+1,dp));
        return dp[i][j];
    }
    int longestPalinSubseq(string a) {
        string b = a;
        std::reverse(a.begin(), a.end());
        int n = a.length();
        vector<vector<int>>dp(n+1, vector<int>(n+1,-1));
        return solve(a,b,0,0,dp);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    
cout << "~" << "\n";
}
}
// Contributed By: Pranay Bansal

// } Driver Code Ends