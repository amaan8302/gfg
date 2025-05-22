class Solution {
  public:
    int solve(int i, int j, string &text1, string &text2, vector<vector<int>> &dp) 
    {
        if(i == 0 || j == 0) return 0;
    
        if(dp[i][j] != -1) return dp[i][j];
    
        if(text1[i - 1] == text2[j - 1])
            return dp[i][j] = 1 + solve(i - 1, j - 1, text1, text2, dp);
        else
            return dp[i][j] = max(solve(i - 1, j, text1, text2, dp), solve(i, j - 1, text1, text2, dp));
    }
    int minDeletions(string s) {
        string a = s;
        std::reverse(a.begin(),a.end());
        vector<vector<int>>dp(s.length()+1,vector<int>(s.length()+1,-1));
        return s.length()-solve(s.length(),s.length(),a,s,dp);;
    }
};