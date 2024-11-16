//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long solve(int i , vector<long long>&prices , bool buy, int n
    ,vector<vector<int>>&dp)
    {
        if(i>=n)
            return 0;
        if(dp[i][buy]!=-1)
            return dp[i][buy];
        long long profit;
        if(buy)
        {
            long long buyKaro = -prices[i] + solve(i+1, prices,false,n,dp);
            long long excl = solve(i+1,prices,true,n,dp);
            profit = max(buyKaro , excl);
        }    
        else
        {
            long long sellKaro = prices[i] + solve(i+2, prices,true,n,dp);
            long long excl = solve(i+1,prices,false,n,dp);
            profit = max(sellKaro , excl);
        }
        return dp[i][buy] = profit;
    }
    long long maximumProfit(vector<long long>&prices, int n) 
    {
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return solve(0,prices,true,n,dp);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> prices;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            prices.push_back(x);
        }
        
        Solution obj;
        cout<<obj.maximumProfit(prices, n)<<"\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends