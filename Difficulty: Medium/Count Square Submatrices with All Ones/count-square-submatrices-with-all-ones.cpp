//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int solve(int i , int j , vector<vector<int>>& matrix,vector<vector<int>>&dp)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        if(i<0 || i>=m || j<0 || j>=n ||matrix[i][j]!=1)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int right = solve(i,j+1,matrix,dp);
        int down = solve(i+1,j,matrix,dp);
        int diagonal = solve(i+1,j+1,matrix,dp);
        return dp[i][j] = 1 + min({right,down,diagonal});
    }
    int countSquares(int m, int n, vector<vector<int>> &matrix) {
        // code here
        int cnt = 0;
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(matrix[i][j]==1)
                    cnt+= solve(i,j,matrix,dp);
            }
        }
        return cnt;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;

        vector<vector<int>> matrix(N, vector<int>(M));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        cout << obj.countSquares(N, M, matrix) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends