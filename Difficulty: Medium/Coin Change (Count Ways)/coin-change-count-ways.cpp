//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long int solve(int i, int amount,vector<int>& coins,int n,vector<vector<long long int>>&dp)
    {
        if(amount==0)
            return 1;
        if(i>=n)
            return 0;
        if(coins[i]>amount)
            return solve(i+1,amount,coins,n,dp);
        if(dp[i][amount]!=-1)
            return dp[i][amount];
        long long int take = solve(i,amount - coins[i] , coins,n,dp);
        long long int skip = solve(i+1 , amount , coins,n,dp);
        return dp[i][amount] = take + skip;
    }
    long long int count(vector<int> coins, int amount) {
        // code here.
        int n = coins.size();
        vector<vector<long long int>>dp(n+1,vector<long long int>(amount+1,-1));
        return solve(0,amount,coins,n,dp);
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