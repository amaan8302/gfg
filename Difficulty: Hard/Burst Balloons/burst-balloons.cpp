//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    int solve(int i , int n , vector<int>& nums,vector<vector<int>>&dp)
    {
        if(i>n)
            return 0;
        if(dp[i][n]!=-1)
            return dp[i][n];
        int maxi = INT_MIN;
        for(int m = i ; m<=n ; m++)
        {
            int cost = nums[i-1]*nums[m]*nums[n+1] + solve(i,m-1,nums,dp)+solve(m+1,n,nums,dp);
            maxi = max(maxi,cost);
        }
        return dp[i][n]=maxi;
    }
    int maxCoins(int n, vector<int> &nums) 
    {
        // int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        return solve(1,n,nums,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        vector<int> arr(N);
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution obj;
        cout << obj.maxCoins(N, arr) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends