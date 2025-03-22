//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(vector<int>& arr , vector<int>& dp, int i)
    {
        if(i>=arr.size())
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int yes = arr[i]+solve(arr,dp,i+2);
        int no = solve(arr,dp,i+1);
        return dp[i]=max(yes,no);
    }
    int maxValue(vector<int>& arr) {
        int n = arr.size();
        vector<int>arr1(n-1,0);
        vector<int>arr2(n-1,0);
        for (int i = 0; i < n - 1; i++)
            arr1[i] = arr[i];
        for (int i = 1; i < n; i++)
            arr2[i - 1] = arr[i];
        vector<int>dp1(n,-1);
        vector<int>dp2(n,-1);
        return max(solve(arr1,dp1,0),solve(arr2,dp2,0));
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        int res;
        res = ob.maxValue(arr);
        cout << res << "\n"
             << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends