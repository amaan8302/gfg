//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
    const int mod = 1e9 + 7;
    long long solve(vector<int>& nums, int target, int index, int sum, vector<vector<int>>& dp) 
    {
        if (index == nums.size()) 
        {
            if (target == sum)
                return 1;
            else 
                return 0;
        }
        // if (dp[index][sum] != -1)
        //     return dp[index][sum];
        int plus = solve(nums, target, index + 1, sum + nums[index], dp);
        int minus = solve(nums, target, index + 1, sum - nums[index], dp);
        return (plus + minus)%mod;
    }
    long long findTargetSumWays(int n, vector<int>& A, int target) {
        // Your code here
        vector<vector<int>>dp;
        return solve(A,target,0,0,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin >> N;
        vector<int> arr(N);

        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout << ob.findTargetSumWays(N, arr, target);
        cout << "\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends