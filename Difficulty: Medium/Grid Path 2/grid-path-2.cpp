//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    const int mod = 1e9+7;
    int solve(int n , int m , vector<vector<int>>& grid , 
    int i , int j,vector<vector<int>>&dp)
    {
        if(n==1 && m == 1 && grid[0][0]==1)
            return 0;
        if(n==1 && m == 1 && grid[0][0]==0)
            return 1;
        if(i == n-1 && j == m-1)
            return 1;
        if(i>=n || j>=m || grid[i][j]==1 || grid[n-1][m-1]==1)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j]; 
        int down = solve(n,m,grid,i,j+1,dp);
        int right  = solve(n,m,grid,i+1,j,dp);
        return dp[i][j] = (down + right)%mod;
    }
    int totalWays(int n, int m, vector<vector<int>>& grid) {
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(n,m,grid,0,0,dp);        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < m; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.totalWays(n, m, grid) << "\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends