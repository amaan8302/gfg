//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    int maxProduct(vector<int> &arr) {
        int prefix = 1, suffix = 1, n = arr.size();
        int i = 0 , j = n-1,maxi = INT_MIN;
        while(i<n && j >=0)
        {
            prefix *= arr[i];
            suffix *= arr[j];
            maxi = max({maxi,prefix,suffix});
            if(arr[i]==0)
                prefix = 1;
            if(arr[j]==0)
                suffix=1;
            i++;
            j--;
        }
        return maxi;
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