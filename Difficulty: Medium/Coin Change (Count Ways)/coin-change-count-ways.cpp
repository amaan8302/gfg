//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int solve(int i, int amount, int coins[], int n, vector<vector<long long int>>& dp) {
    if (amount == 0)
        return 1;
    if (i >= n || amount < 0)
        return 0;
    if (dp[i][amount] != -1)
        return dp[i][amount];

    long long int take = 0;
    if (coins[i] <= amount)
        take = solve(i, amount - coins[i], coins, n, dp);
    long long int skip = solve(i + 1, amount, coins, n, dp);
    
    return dp[i][amount] = take + skip;
}

long long int count(int coins[], int n, int amount) {
    vector<vector<long long int>> dp(n, vector<long long int>(amount + 1, -1));
    return solve(0, amount, coins, n, dp);
}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends