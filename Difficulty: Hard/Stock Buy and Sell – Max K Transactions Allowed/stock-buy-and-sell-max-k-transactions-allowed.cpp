//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int solve(int price[] , bool buy , int i, int n,int k
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
    int maxProfit(int k, int n, int A[]){
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2,vector<int>(k+1,-1)));
        return solve(A , true , 0 , n , k ,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends