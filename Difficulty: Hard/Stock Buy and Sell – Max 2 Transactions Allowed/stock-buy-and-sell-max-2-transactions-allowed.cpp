//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(vector<int>& prices, int k , bool buy , int i,vector<vector<vector<int>>>&dp)
    {
        if(i>=prices.size())
            return 0;
        if(k<=0)
            return 0;
        if(dp[i][k][buy]!=-1)
            return dp[i][k][buy];
        int profit;
        if(buy)
        {
            int buy = solve(prices , k , 0 , i+1,dp)-prices[i];
            int excl = solve(prices,k,1,i+1,dp);
            profit = max(buy,excl);
        }
        else
        {
            int sell = solve(prices,k-1,1,i+1,dp)+prices[i];
            int excl = solve(prices,k,0,i+1,dp);
            profit = max(sell,excl);
        }
        return dp[i][k][buy] = profit;
    }
    int maxProfit(vector<int> &prices) {
        vector<vector<vector<int>>>dp(prices.size(),vector<vector<int>>(3,vector<int>(3,-1)));
        return solve(prices,2,1,0,dp);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxProfit(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends