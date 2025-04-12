//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool canJumpFrom(int index, vector<int>& nums, vector<int>& dp) 
    {
        if (index >= nums.size() - 1) return true;
        if (dp[index] != -1) return dp[index];
    
        int maxJump = nums[index];
        for (int jump = 1; jump <= maxJump; jump++) {
            if (canJumpFrom(index + jump, nums, dp)) {
                return dp[index] = true;
            }
        }
        return dp[index] = false;
    }
    bool canReach(vector<int> &nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return canJumpFrom(0, nums, dp);
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> a;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        int ans = ob.canReach(a);

        if (ans) {
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends