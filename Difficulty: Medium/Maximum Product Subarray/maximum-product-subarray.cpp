//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int solve(vector<int>& nums, int i, int maxProd, int minProd, int& result) 
    {
        int n = nums.size();
        if (i >= n)
            return result;
        
        int tempMax = max({nums[i], maxProd * nums[i], minProd * nums[i]});
        int tempMin = min({nums[i], maxProd * nums[i], minProd * nums[i]});
        
        result = max(result, tempMax);
        
        return solve(nums, i + 1, tempMax, tempMin, result);
    }
    int maxProduct(vector<int> &nums) {
        int result = nums[0];
        return solve(nums, 1, nums[0], nums[0], result);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // int n, i;
        // cin >> n;
        // vector<int> arr(n);
        // for (i = 0; i < n; i++) {
        //     cin >> arr[i];
        // }

        vector<int> arr;
        string input;

        // Read array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        auto ans = ob.maxProduct(arr);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends