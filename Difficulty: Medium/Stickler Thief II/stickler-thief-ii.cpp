//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(vector<int>& arr, vector<int>& dp, int i, int end)
    {
        if (i > end)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int rob = arr[i] + solve(arr, dp, i + 2, end);
        int norob = solve(arr, dp, i + 1, end);
        return dp[i] = max(rob, norob);
    }
    
    int maxValue(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return arr[0];
        vector<int> dp1(n, -1), dp2(n, -1);
        return max(solve(arr, dp1, 0, n - 2), solve(arr, dp2, 1, n - 1));
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