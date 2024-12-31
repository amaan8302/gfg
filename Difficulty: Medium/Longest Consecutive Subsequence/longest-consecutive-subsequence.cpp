//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestConsecutive(vector<int>& nums)
    {
        if (nums.empty()) return 0; // Handle empty input
        std::sort(nums.begin(), nums.end());
        int prev = nums[0];
        int curr = nums[0];
        int cnt = 1;
        int longest = 1; // Initialize with 1, as the smallest sequence has at least one element
        for (int i = 1; i < nums.size(); i++) {
            curr = nums[i];
            if (curr == prev) continue; // Skip duplicates
            if (curr != prev + 1) {
                cnt = 1;
            } else {
                cnt++;
            }
            longest = max(longest, cnt);
            prev = curr;
        }
        return longest;
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
        int res = ob.longestConsecutive(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends