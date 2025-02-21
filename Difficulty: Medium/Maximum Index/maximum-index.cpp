//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxIndexDiff(vector<int>& arr) {
    int n = arr.size();
    if (n < 2) return 0;
    
    // Create arrays to store left minimums and right maximums
    vector<int> leftMin(n);
    vector<int> rightMax(n);
    
    // Fill leftMin array
    // leftMin[i] stores the minimum value from index 0 to i
    leftMin[0] = arr[0];
    for (int i = 1; i < n; i++) {
        leftMin[i] = min(arr[i], leftMin[i-1]);
    }
    
    // Fill rightMax array
    // rightMax[i] stores the maximum value from index i to n-1
    rightMax[n-1] = arr[n-1];
    for (int i = n-2; i >= 0; i--) {
        rightMax[i] = max(arr[i], rightMax[i+1]);
    }
    
    // Find the maximum j-i where leftMin[i] <= rightMax[j]
    int i = 0, j = 0, maxDiff = -1;
    while (i < n && j < n) {
        if (leftMin[i] <= rightMax[j]) {
            // If current elements satisfy our condition,
            // update maxDiff and try to find a larger j
            maxDiff = max(maxDiff, j - i);
            j++;
        } else {
            // If condition not satisfied, we need a smaller left element
            i++;
        }
    }
    
    return maxDiff;
}

};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;

        // calling maxIndexDiff() function
        cout << ob.maxIndexDiff(nums) << endl;
    }

    return 0;
}
// } Driver Code Ends