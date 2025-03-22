//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(int i , string &d , int n ,vector<int>&dp)
    {
        if(i==n)
            return 1;
        if(d[i]=='0')
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int one = solve(i+1,d,n,dp);
        int second = 0;
        if(i+1<n)
        {
            if(d[i]=='1'||(d[i]=='2' && d[i+1]<='6'))
                second = solve(i+2,d,n,dp);
        }
        return dp[i] = one+second;
    }
    int countWays(string &d) {
        int n = d.length();
        if(n==1)
            return 1;
        if(d[0]=='0')
            return 0;
        vector<int>dp(n+1,-1);   
        return solve(0,d,n,dp);
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        string digits;
        getline(cin, digits);
        Solution obj;
        int ans = obj.countWays(digits);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends