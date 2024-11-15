//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solve(int i, vector<int>& prices, int mini,vector<int>&dp) 
    {
        if (i == prices.size()) return 0;
        if (dp[i] != -1) return dp[i];
        int profit = max(solve(i + 1, prices, min(mini, prices[i]),dp), prices[i] - mini);
        dp[i] = profit;
        return dp[i];
    }
    int maximumProfit(vector<int> &prices) {
        // code here
        int n = prices.size();
        vector<int>dp(n+1,-1);
        return solve(0, prices, prices[0],dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> prices;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            prices.push_back(number);
        }

        Solution ob;
        int ans = ob.maximumProfit(prices);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends