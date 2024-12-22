//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int kadaneMin(vector<int> &nums)
    {
        int maxSum = nums[0];
        int currentSum = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            currentSum = std::min(nums[i], currentSum + nums[i]);
            maxSum = std::min(maxSum, currentSum);
        }
        return maxSum;
    }
    int kadaneMax(vector<int> &nums)
    {
        int maxSum = nums[0];
        int currentSum = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            currentSum = std::max(nums[i], currentSum + nums[i]);
            maxSum = std::max(maxSum, currentSum);
        }
        return maxSum;
    }
    int circularSubarraySum(vector<int> &nums) {
        int sum = 0;
        for(int i = 0 ; i < nums.size() ; i++)
            sum+=nums[i];
        int minSum = kadaneMin(nums), maxSum = kadaneMax(nums), circular = sum - minSum;
        if(maxSum>0)
            return max(maxSum,circular);
        return maxSum;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.circularSubarraySum(arr);

        cout << res << endl;
    }
    return 0;
}

// } Driver Code Ends