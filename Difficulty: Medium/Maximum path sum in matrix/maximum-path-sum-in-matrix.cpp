//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(vector<vector<int>>& grid, int row, int col, int m, int n, vector<vector<int>>& dp)
    {
        if (row >= m || col < 0 || col >= n)
            return 0;
        if (dp[row][col] != -1)
            return dp[row][col];
        if (row == m - 1)
            return grid[row][col];
        
        int first = grid[row][col] + solve(grid, row+1, col, m, n, dp);
        int second = grid[row][col] + solve(grid, row+1, col+1, m, n, dp);
        int third = grid[row][col] + solve(grid, row+1, col-1, m, n, dp);
        
        dp[row][col] = max(first, max(second, third));
        return dp[row][col];
    }
    
    int maximumPath(int N, vector<vector<int>> grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        int result = 0;
        for (int i = 0; i < n; i++) {
            result = max(result, solve(grid, 0, i, m, n, dp));
        }
        
        return result;
    }

};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends