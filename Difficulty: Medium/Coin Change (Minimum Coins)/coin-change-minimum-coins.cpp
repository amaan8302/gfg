//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int solve1(vector<int> &num, int x)
    {
        if(x==0)
            return 0;
        if(x<0)
            return INT_MAX;
        int mini = INT_MAX;
        for(int i = 0 ; i < num.size() ; i++)
        {
            int ans = solve1(num , x-num[i]);
            if(ans!=INT_MAX)
                mini = min(1+ans,mini);
        }
        return mini;
    }
    int solve(vector<int> &num, int x ,vector<int>&dp)
    {
        if(x==0)
            return 0;
        if(x<0)
            return INT_MAX;
        if(dp[x]!=-1)
            return dp[x];
        int mini = INT_MAX;
        for(int i = 0 ; i < num.size() ; i++)
        {
            int ans = solve1(num , x-num[i]);
            if(ans!=INT_MAX)
                mini = min(1+ans,mini);
        }
        dp[x]=mini;
        return mini;
    }
    int minCoins(vector<int> &num, int x) {
        vector<int>dp(x+1,INT_MAX);
        dp[0]=0;
        //dp[i] min number of points required to make target 'i'
        for(int i = 1 ; i <= x ; i++)
        {
            //trying to solve for every figure from 1 to x
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