//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // bool solve(vector<int>& arr, int target,int idx,vector<vector<int>>&dp)
    // {
    //     if(idx==arr.size())
    //         return 0;
    //     if(target==0)
    //         return 1;
    //     if(dp[idx][target]!=-1)
    //         return dp[idx][target];
    //     bool incl = solve(arr,target-arr[idx],idx+1,dp);
    //     bool excl = solve(arr,target,idx+1,dp);
    //     return incl||excl;
    // }
    // bool isSubsetSum(vector<int>& arr, int target) {
    //     if(arr.size()==0)
    //     {
    //         if(target==0)
    //             return 1;
    //         else
    //             return 0;
    //     }
    //     if(arr.size()==1)
    //     {
    //         if(target==arr[0])
    //             return true;
    //         else 
    //             return false;
    //     }
    //     vector<vector<int>>dp(arr.size()+1,vector<int>(target+1,-1));
    //     return solve(arr,target,0,dp);
    // }
    bool isSubsetSum(vector<int>& arr, int target) {
    int n = arr.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

    // Base case: target 0 is always achievable with an empty subset
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = true;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= target; ++j) {
            if (arr[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][target];
}

};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends