//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        std::sort(a.begin(),a.end());
        int i = 0,n=a.size();
        int j = m-1;
        int mini = INT_MAX;
        while(j<n)
        {
            mini = min(mini,a[j]-a[i]);
            i++;
            j++;
        }
        return mini;
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

        int m;
        cin >> m;
        cin.ignore();
        Solution ob;
        cout << ob.findMinDiff(arr, m) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends