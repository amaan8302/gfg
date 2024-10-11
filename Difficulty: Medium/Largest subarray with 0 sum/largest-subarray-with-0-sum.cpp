//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution {
  public:
    int maxLen(vector<int>& nums, int n) {
    unordered_map<int, int> sumMap;
    int sum = 0, maxLength = 0;

    for(int i = 0; i < n; i++) {
        sum += nums[i];

        if(sum == 0) {
            maxLength = i + 1;
        }
        
        if(sumMap.find(sum) != sumMap.end()) {
            maxLength = max(maxLength, i - sumMap[sum]);
        } else {
            sumMap[sum] = i;
        }
    }

    return maxLength;
}


};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m;
        cin >> m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i) {
            cin >> array1[i];
        }
        Solution ob;
        cout << ob.maxLen(array1, m) << endl;
    }
    return 0;
}

// } Driver Code Ends