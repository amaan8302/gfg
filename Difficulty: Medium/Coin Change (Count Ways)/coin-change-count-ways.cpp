//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(vector<int>& coins, int amount , int i,vector<vector<int>>&dp)
    {
        if(amount == 0)
            return 1;
        if(i >= coins.size() || amount<0 )
            return 0;
        if(dp[i][amount]!=-1)
            return dp[i][amount];
        int take = 0;
        if(amount - coins[i] >= 0)
            take = solve(coins,amount-coins[i],i,dp);
        int skip = solve(coins, amount , i+1,dp);
        return dp[i][amount] = take + skip;
    }
    int count(vector<int>& coins, int sum) 
    {
        int n = coins.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return solve(coins,sum,0,dp);
        // vector<vector<int>>dp(n+1,vector<int>(sum+1,0));
        // for(int i = 0 ; i <= n ; i++)
        //     dp[i][0]=1;
        // for(int i = n-1 ; i >=0 ; i--)
        // {
        //     for(int amount = 0 ; amount <= sum ; amount++)
        //     {
        //         int take = 0;
        //         if(amount - coins[i] >= 0)
        //             take = dp[i][amount-coins[i]];
        //         int skip = dp[i+1][amount];
        //         dp[i][amount] = take+skip;
        //     }
        // }
        // return dp[0][sum];
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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();
        Solution ob;
        cout << ob.count(arr, sum) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends