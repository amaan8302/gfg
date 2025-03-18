//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool equalPartition(vector<int>& arr) {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if (sum % 2 != 0) return false;
        int total = sum / 2;
        vector<int> curr(total + 1, 0), next(total + 1, 0);
        next[0] = 1;
        
        for (int index = arr.size() - 1; index >= 0; index--)
        {
            for (int target = total; target >= 1; target--) {   
                bool incl = (target - arr[index] >= 0) ? next[target - arr[index]] : false;
                bool excl = next[target];
                curr[target] = incl || excl;
            }
            next = curr;
        }
        return next[total];
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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        if (ob.equalPartition(arr))
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends