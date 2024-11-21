//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
        int solve(vector<int>&price , bool buy , int i, int n,int k
        ,vector<vector<vector<int>>>&dp)
        {
            if(i>=n)
                return 0;
            if(k==0)
                return 0;
            if(dp[i][buy][k]!=-1)
                return dp[i][buy][k];
            int profit;
            if(buy){
                int buyKaro = -price[i] + solve(price,0,i+1,n,k,dp);
                int excl = solve(price,1,i+1,n,k,dp);
                profit = max(buyKaro,excl);
            }
            else{
                int sellKaro = price[i] + solve(price,1,i+1,n,k-1,dp);
                int excl = solve(price,0,i+1,n,k,dp);
                profit = max(sellKaro,excl);
            }
            return dp[i][buy][k] = profit;
        }
        int maxProfit(vector<int>&price){
            int n = price.size();
            vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2,vector<int>(3,-1)));
            return solve(price , true , 0 , n , 2,dp);
        }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        Solution obj;
        cout<<obj.maxProfit(price)<<endl;
    
cout << "~" << "\n";
}

}

// } Driver Code Ends