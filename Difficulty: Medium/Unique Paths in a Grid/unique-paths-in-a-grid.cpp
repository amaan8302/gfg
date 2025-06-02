class Solution {
  public:
    int solve(int i , int j , int m , int n , vector<vector<int>>&grid,vector<vector<int>>&dp)
    {
        if(i>=m || j>=n || grid[i][j]==1)
            return 0;
        if(i == m-1 && j == n-1)
            return 1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int right = solve(i+1,j,m,n,grid,dp);
        int down = solve(i,j+1,m,n,grid,dp);
        return dp[i][j] = right+down;
    }
    int uniquePaths(vector<vector<int>> &grid) 
    {
        vector<vector<int>>dp(grid.size()+1,vector<int>(grid[0].size(),-1));
        return solve(0,0,grid.size(),grid[0].size(),grid,dp);
    }
};