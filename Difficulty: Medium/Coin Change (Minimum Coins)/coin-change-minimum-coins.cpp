//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solveTab(vector<int> &num, int x)
    {
        vector<int>dp(x+1,INT_MAX);
        dp[0]=0;
        for(int i = 1 ; i <= x ; i++)
        {
            for(int j = 0 ; j < num.size();j++)
            {
                if(i-num[j]>=0 && dp[i-num[j]]!=INT_MAX)
                dp[i]=min(dp[i],1+dp[i-num[j]]);
            }
        }
        if(dp[x]==INT_MAX)
            return -1;
        return dp[x];
    }
    int minCoins(vector<int> &coins, int sum) {
        return solveTab(coins,sum);
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minCoins(arr, k);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends