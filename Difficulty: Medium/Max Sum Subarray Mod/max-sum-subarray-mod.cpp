//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    int maxSub(vector<int>& arr, int m) {
        set<long> prefixSet;
        long maxModSum = 0, currPrefix = 0;
        prefixSet.insert(0);
        for (long num : arr) {
            currPrefix = (currPrefix + num % m) % m;
            maxModSum = max(maxModSum, currPrefix);
            auto it = prefixSet.upper_bound(currPrefix);
            if (it != prefixSet.end()) {
                maxModSum = max(maxModSum, (currPrefix - *it + m) % m);
            }
            prefixSet.insert(currPrefix);
        }
        return maxModSum;
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
        int m;
        getline(cin, input);
        stringstream ss1(input);
        ss1 >> m;
        Solution obj;
        int ans = obj.maxSub(arr, m);
        cout << ans << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends