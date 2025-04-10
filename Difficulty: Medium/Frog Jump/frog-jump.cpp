//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(int i, vector<int>& height, int n, vector<int>&dp)
    {
        if(i == n - 1)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int one = INT_MAX, two = INT_MAX;
        if(i + 1 < n)
            one = abs(height[i] - height[i + 1]) + solve(i + 1, height, n,dp);
        if(i + 2 < n)
            two = abs(height[i] - height[i + 2]) + solve(i + 2, height, n,dp);
        return dp[i] = min(one, two);
    }
    int minCost(vector<int>& height) {
        int n = height.size();
        vector<int>dp(n+1,-1);
        return solve(0, height, height.size(),dp);
    }
};


//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends