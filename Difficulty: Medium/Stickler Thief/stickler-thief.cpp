//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


// } Driver Code Ends

class Solution {
  public:
    int solve(vector<int>& arr , int i,vector<int>&dp)
    {
        if(i>=arr.size())
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int take = arr[i] + solve(arr,i+2,dp);
        int notake = solve(arr,i+1,dp);
        return dp[i] = max(take,notake);
    }
    int findMaxSum(vector<int>& arr) {
        vector<int>dp(arr.size()+1,-1);
        return solve(arr,0,dp);
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

        Solution ob;
        cout << ob.findMaxSum(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends