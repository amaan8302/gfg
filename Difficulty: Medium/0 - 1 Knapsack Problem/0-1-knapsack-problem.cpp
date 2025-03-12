//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to return max value that can be put in knapsack of capacity.
    int knapsack(int capacity, vector<int> &values, vector<int> &weights) {
        // code here
        
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
    // Taking total test cases
    int testCases;
    cin >> testCases;
    cin.ignore();
    while (testCases--) {
        // Reading number of items and capacity
        int numberOfItems, capacity;
        vector<int> weights, values;
        string input;
        int number;

        // Read capacity and number of items
        getline(cin, input);
        stringstream ss(input);
        ss >> capacity;      // The first number is the capacity
        ss >> numberOfItems; // The second number is the number of items

        // Read values
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            values.push_back(number);
        }

        // Read weights
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            weights.push_back(number);
        }

        Solution solution;
        cout << solution.knapsack(capacity, values, weights) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends