class Solution {
  public:
    int solve(int i, int j,int n,vector<vector<int>>&matrix,vector<vector<vector<int>>>&dp)
    {
        if(i>3 || j>2 || i<0||j<0||matrix[i][j]==-1)
            return 0;
        if(n==0) return 1;
        if(dp[i][j][n]!=-1)
            return dp[i][j][n];
        int ans = solve(i,j,n-1,matrix,dp)
        +solve(i-1,j,n-1,matrix,dp)+solve(i+1,j,n-1,matrix,dp)
        +solve(i,j-1,n-1,matrix,dp)+solve(i,j+1,n-1,matrix,dp);
        return dp[i][j][n] = ans;
    }
    
    int getCount(int n) {
        vector<vector<int>>matrix(4,vector<int>(3,1));
        matrix[3][0]=-1;
        matrix[3][2]=-1;
        int cnt = 0;
        vector<vector<vector<int>>>dp(5,vector<vector<int>>(4,vector<int>(n+1,-1)));
        for(int i = 0 ; i < 4 ; i++)
        {
            for(int j = 0 ; j < 3 ; j++)
            {
                if(matrix[i][j]!=-1)
                cnt+=solve(i,j,n-1,matrix,dp);
            }
        }
        return cnt;
    }
};