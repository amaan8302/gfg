//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int minRemoval(vector<int>& arr) 
    {
        sort(arr.begin(), arr.end());
        int n = arr.size(), minRemovals = n;
        int left = 0;
    
        for (int right = 0; right < n; right++) {
            while (arr[left] * 2 < arr[right]) {
                left++;
            }
            minRemovals = min(minRemovals, n - (right - left + 1));
        }
        
        return minRemovals;
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
        cout << ob.minRemoval(nums) << endl;
    }
    return 0;
}

// } Driver Code Ends