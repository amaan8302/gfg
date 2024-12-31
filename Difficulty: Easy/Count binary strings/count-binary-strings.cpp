//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    int countStrings(int n, int k)
    {
        const int MOD = 1e9 + 7;
        vector<vector<vector<long long>>> dp(n + 1, 
            vector<vector<long long>>(k + 1, 
                vector<long long>(2, 0)));
        
        dp[1][0][0] = 1;
        dp[1][0][1] = 1;
        
        for(int i = 2; i <= n; i++) {
            for(int j = 0; j <= k; j++) {
                dp[i][j][0] = (dp[i-1][j][0] + dp[i-1][j][1]) % MOD;
                
                if(j > 0) {
                    dp[i][j][1] = dp[i-1][j-1][1] % MOD;
                }
                dp[i][j][1] = (dp[i][j][1] + dp[i-1][j][0]) % MOD;
            }
        }
        
        return (dp[n][k][0] + dp[n][k][1]) % MOD;
    }
 
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        Solution ob;
        cout<<ob.countStrings(n,k)<<"\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends