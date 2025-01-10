//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    int minOperation(int n)
    {
        if (n <= 1) return n;
        
        vector<int> dp(n + 1, INT_MAX);
        dp[1] = 0;
        
        for (int i = 1; i <= n; i++) {
            if (i + 1 <= n) {
                dp[i + 1] = min(dp[i + 1], dp[i] + 1);
            }
            
            if (i * 2 <= n) {
                dp[i * 2] = min(dp[i * 2], dp[i] + 1);
            }
        }
        
        return dp[n] + 1;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	    {
	        int n;
	        cin>>n;
	        Solution ob;
	        cout<<ob.minOperation(n)<<endl;
	    
cout << "~" << "\n";
}
}
// } Driver Code Ends