// User function Template for C++
class Solution {
  public:
    int solve(int i , int j , int m , int n,vector<vector<int>>&dp)
    {
        if(i>=m || j>=n)
            return 0;
        if(i==m-1 && j ==n-1)
            return 1;
        if(dp[i][j]!=-2)
            return dp[i][j];
        int right = solve(i+1,j,m,n,dp);
        int down = solve(i,j+1,m,n,dp);
        return dp[i][j] = right+down;
    }
    int numberOfPaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,-2));
        return solve(0,0,m,n,dp);
    }
};