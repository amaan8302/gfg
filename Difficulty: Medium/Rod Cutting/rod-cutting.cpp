//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int solve(int index , int n ,int price[],vector<vector<int>>&dp)
    {
    	if(index==0)
    		return n*price[0];
    	if(dp[index][n]!=-1)
    		return dp[index][n];
    	int no = solve(index-1,n,price,dp);
    	int yes = INT_MIN;
    	int len = index+1;
    	if(len<=n)
    		yes = price[index]+solve(index,n-len,price,dp);
    	return dp[index][n]=max(yes,no);
    }
    int cutRod(int price[], int n) {
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
	    return solve(n-1,n,price,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends