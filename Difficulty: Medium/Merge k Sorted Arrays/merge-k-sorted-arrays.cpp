//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
#define N 105
using namespace std;

void printArray(vector<int> arr, int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> mergeKArrays(vector<vector<int>>& arr, int k) {
        vector<int>r;
        for(int i = 0 ; i < k ; i++)
        {
            for(int j = 0 ; j < k ; j++)
                r.push_back(arr[i][j]);
        }
        sort(r.begin(),r.end());
        return r;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        vector<vector<int>> arr(k, vector<int>(k, 0));
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                cin >> arr[i][j];
            }
        }
        Solution obj;
        vector<int> output = obj.mergeKArrays(arr, k);
        printArray(output, k * k);
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends