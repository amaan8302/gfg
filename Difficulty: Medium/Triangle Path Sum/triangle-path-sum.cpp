//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int solve(vector<vector<int>>& triangle, int i , int j, int row,vector<vector<int>>&dp)
    {
        if(row==1)
            return triangle[0][0];
        if(i>=row)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int first = triangle[i][j]+solve(triangle,i+1,j,row,dp);
        int second = triangle[i][j]+solve(triangle,i+1,j+1,row,dp);
        return dp[i][j] = min(first,second);
    }
    int minimizeSum(int row, vector<vector<int>>& triangle) {
        // Code here
        // int row = triangle.size();
        vector<vector<int>>dp(row+1,vector<int>(row+1,-1));
        return solve(triangle,0,0,row,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> triangle;

        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j <= i; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            triangle.push_back(temp);
        }
        Solution obj;
        cout << obj.minimizeSum(n, triangle) << "\n";
    }
    return 0;
}
// } Driver Code Ends