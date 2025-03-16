//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(vector<int>& arr, int i,vector<int>&dp)
    {
        if (i >= arr.size() - 1) 
            return 0;
        if (arr[i] == 0) 
            return INT_MAX;
        if(dp[i]!=-1)
            return dp[i];
        int minJump = INT_MAX;
        for (int j = 1; j <= arr[i] && i + j < arr.size(); j++)
        {
            int res = solve(arr, i + j,dp);
            if (res != INT_MAX)
                minJump = min(minJump, 1 + res);
        }
        return dp[i] = minJump;
    }
    
    int minJumps(vector<int>& arr) 
    {
        if(arr[0]==0)
            return -1;
        vector<int>dp(arr.size()+1,-1);
        int ans = solve(arr, 0,dp);
        return ans== INT_MAX ? -1 : ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl << "~\n";
    }
    return 0;
}

// } Driver Code Ends