//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int solve(int n , int k , int i,vector<int>&dp)
    {
        if(i>n)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int take = k + solve(n,k,i+2,dp);
        int no = solve(n,k,i+1,dp);
        return dp[i]=max(take , no);
    }
    int maximizeMoney(int n , int k) {
        // code here
        vector<int>dp(n+1,-1);
        return solve(n,k,1,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;

        cin>>N>>K;

        Solution ob;
        cout << ob.maximizeMoney(N,K) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends