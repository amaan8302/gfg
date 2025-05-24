// User function template in C++

class Solution {
  public:
    int solve(int a , int b , int i , int j,vector<vector<int>>&dp)
    {
        if(i>=a || j>=b)
            return 0;
        if(i == a-1 && j == b-1)
            return 1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int down = solve(a,b,i+1,j,dp);
        int right = solve(a,b,i,j+1,dp);
        return dp[i][j] = down + right;
    }
    int NumberOfPath(int a, int b) {
        vector<vector<int>>dp(a+1,vector<int>(b+1,-1));
        return solve(a,b,0,0,dp);
    }
};
