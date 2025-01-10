//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solve(int m, int n, int i, int j,vector<vector<int>>&dp) 
    {
        if (i == m - 1 && j == n - 1) 
            return 1;
        if (i >= m || j >= n) 
            return 0; 
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans = solve(m, n, i + 1, j,dp) + solve(m, n, i, j + 1,dp);
        return  dp[i][j] = ans;
    }
    int numberOfPaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solve(m, n, 0, 0,dp);
    }


};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        cout << ob.numberOfPaths(arr[0], arr[1]) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends