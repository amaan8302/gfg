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
    int maxProfit(vector<int>& prices, int k) {
        vector<vector<vector<int>>>dp(prices.size(),vector<vector<int>>(k+1,vector<int>(3,-1)));
        return solve(prices,k,1,0,dp);
    }
    
};


//{ Driver Code Starts.

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        istringstream iss(input);
        vector<int> arr;
        int num;

        // Read integers from the input string
        while (iss >> num) {
            arr.push_back(num);
        }
        int k;
        cin >> k;
        cin.ignore();
        Solution ob;
        cout << ob.maxProfit(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends