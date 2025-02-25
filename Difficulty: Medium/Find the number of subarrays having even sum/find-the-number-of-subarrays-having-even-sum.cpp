//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<vector<long long>> dp;
    long long countSubarrays(int i, int odd, vector<int>& arr) {
        if (i < 0) return 0;
        if (dp[i][odd] != -1) return dp[i][odd];
        int res = 0;
        if (arr[i] % 2 == 1) 
        {
            if (odd)
                res = 1 + countSubarrays(i - 1, 0, arr);
            else
                res = countSubarrays(i - 1, 1, arr);
        }
        else 
        {
            if (odd)
                res = countSubarrays(i - 1, 1, arr);
            else
                res = 1 + countSubarrays(i - 1, 0, arr);
        }
        return dp[i][odd] = res ;
    }
    long long countEvenSum(vector<int>& arr) {
        int n = arr.size();
        dp.assign(n, vector<long long>(2, -1));
        long long result = 0;
        for (int i = 0; i < n; i++)
            result = (result + countSubarrays(i, 0, arr));
        return result;
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        long long res = obj.countEvenSum(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends