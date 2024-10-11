//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int solve(int arr[], int n, int idx, int prev, vector<vector<int>>& dp) {
    if (idx == n) return 0;
    
    int shiftedPrev = prev + 1; 

    if (dp[idx][shiftedPrev] != -1) 
        return dp[idx][shiftedPrev];

    int notTake = solve(arr, n, idx + 1, prev, dp);

    int take = 0;
    if (prev == -1 || arr[idx] > arr[prev]) 
        take = arr[idx] + solve(arr, n, idx + 1, idx, dp);

    return dp[idx][shiftedPrev] = max(take, notTake);
}

int maxSumIS(int arr[], int n) {
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return solve(arr, n, 0, -1, dp);
}

};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends