//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution 
{
  public:
    bool solve(vector<int>& arr, int target,int idx,vector<vector<int>>&dp)
    {
        if(target == 0) 
            return 1;
        if(idx == arr.size()) 
            return 0;
        if(dp[idx][target] != -1)
            return dp[idx][target];
        bool result = false;
        if(target >= arr[idx])
            result = solve(arr, target - arr[idx], idx + 1, dp);
        if(!result)
            result = solve(arr, target, idx + 1, dp);
        return dp[idx][target] = result;
    }
    bool isSubsetSum(vector<int>& arr, int target) {
        vector<vector<int>>dp(arr.size()+1,vector<int>(target+1,-1));
        return solve(arr,target,0,dp);
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