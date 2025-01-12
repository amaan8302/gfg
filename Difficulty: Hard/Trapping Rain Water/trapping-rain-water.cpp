//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxWater(vector<int> &height) {
        // code here
        int n = height.size();
      int left = 0, right = n - 1;
      int res = 0;
      int maxLeft = 0, maxRight = 0;
      while (left <= right) {
        if (height[left] <= height[right]) {
          if (height[left] >= maxLeft) {
            maxLeft = height[left];
          } else {
            res += maxLeft - height[left];
          }
          left++;
        } else {
          if (height[right] >= maxRight) {
            maxRight = height[right];
          } else {
            res += maxRight - height[right];
          }
          right--;
        }
      }
      return res;
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
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends