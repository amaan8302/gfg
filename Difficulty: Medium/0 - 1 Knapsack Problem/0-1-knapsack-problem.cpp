//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int capacity, vector<int>& weights, vector<int>& values) 
    {
        int n = weights.size();
        vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));
        for (int w = weights[0]; w <= capacity; w++)
        {
            dp[0][w] = values[0];
        }
        for (int i = 1; i < n; i++)
        {
            for (int w = 0; w <= capacity; w++)
            {
                int incl = 0;
                if (weights[i] <= w)
                {
                    incl = values[i] + dp[i - 1][w - weights[i]];
                }
                int excl = dp[i - 1][w];
                dp[i][w] = std::max(incl, excl);
            }
        }
        return dp[n - 1][capacity];
    }
};

//{ Driver Code Starts.

int main() {
    // taking total testcases
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // reading number of elements and weight
        int n, w;
        vector<int> arr, val, wt, drr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }

        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            val.push_back(number);
        }

        w = arr[0];
        n = val.size();
        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            wt.push_back(number);
        }
        Solution ob;
        cout << ob.knapSack(w, wt, val) << endl;
    }
    return 0;
}
// } Driver Code Ends