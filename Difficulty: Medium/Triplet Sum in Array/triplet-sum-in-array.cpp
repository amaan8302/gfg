//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool hasTripletSum(vector<int> &arr, int target) {
        std::sort(arr.begin(), arr.end());
        int n = arr.size();
        int cnt = 0;
        for(int idx = 0 ; idx < n-2 ; idx++)
        {
            int tar = target - arr[idx];
            int i = idx+1;
            int j = n-1;
            while(i<j)
            {
                int sum = arr[i]+arr[j];
                if(sum==tar)
                    return true;
                else if(sum > tar)
                    j--;
                else
                    i++;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int target;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> target;
        cin.ignore(); // Ignore newline character after target input

        Solution solution;
        bool result = solution.hasTripletSum(arr, target);
        cout << (result ? "true" : "false") << "\n";
    }

    return 0;
}
// } Driver Code Ends