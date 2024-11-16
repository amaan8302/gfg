//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long solve(vector<int>& arr, int k , int i , bool buy,int n,
    vector<vector<int>>&dp)
    {
        if(i>=n)
            return 0;
        if(dp[i][buy]!=-1)
            return dp[i][buy];
        long long profit;
        if(buy)
        {
            int buyKaro = -arr[i] + solve(arr,k,i+1,false,n,dp);
            int excl = solve(arr,k,i+1,true,n,dp);
            profit = max(buyKaro,excl);
        }
        else
        {
            int sellKaro = arr[i]-k + solve(arr,k,i+1,true,n,dp);
            int excl = solve(arr,k,i+1,false,n,dp);
            profit = max(sellKaro,excl);
        }
        return dp[i][buy]=profit;
    }
    long long maximumProfit(vector<int>& arr, int k) {
        vector<vector<int>>dp(arr.size()+1,vector<int>(2,-1));
        return solve(arr,k,0,true,arr.size(),dp);
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        long long ans = ob.maximumProfit(arr, k);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends