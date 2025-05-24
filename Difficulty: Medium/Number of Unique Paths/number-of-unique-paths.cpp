// User function template in C++

class Solution {
  public:
    int NumberOfPath(int a, int b) 
    {
        vector<vector<int>>dp(a+1,vector<int>(b+1,0));
        dp[a-1][b-1]=1;
        for(int i = a-1 ; i >= 0 ; i--)
        {
            for(int j = b-1 ; j >= 0 ; j--)
            {
                if (i == a - 1 && j == b - 1) 
                    continue;
                int down = dp[i+1][j];
                int right = dp[i][j+1];
                dp[i][j] = down + right;
            }
        }
        return dp[0][0];
    }
};
