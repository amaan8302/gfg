class Solution {
  public:
    int solve(string& s1, string& s2, string& s3 , int i , int j , int k,
    vector<vector<vector<int>>>&dp)
    {
        if(i>=s1.length()||k>=s3.length()||j>=s2.length())
            return 0;
        if(dp[i][j][k]!=-1)
            return dp[i][j][k];
        if(s1[i]==s2[j] && s2[j]==s3[k])
            return dp[i][j][k] = 1 + solve(s1,s2,s3,i+1,j+1,k+1,dp);
        return dp[i][j][k] = max({solve(s1,s2,s3,i,j,k+1,dp)
        ,solve(s1,s2,s3,i+1,j,k,dp)
        ,solve(s1,s2,s3,i,j+1,k,dp)});
    }
    int lcsOf3(string& s1, string& s2, string& s3) {
        int i = s1.length(),j=s2.length(),k=s3.length();
        vector<vector<vector<int>>>dp(i+1,vector<vector<int>>(j+1,vector<int>(k+1,-1)));
        return solve(s1,s2,s3,0,0,0,dp);
    }
};
