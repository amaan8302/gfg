//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool findTriplets(vector<int> &arr) {
        int n = arr.size();
        std::sort(arr.begin(), arr.end());
        for (int i = 0; i < n - 2; i++) {
            int sum = -arr[i];
            int k = i + 1, j = n - 1;
            while (k < j) {
                int currSum = arr[k] + arr[j];
                if (currSum == sum)
                    return true;
                else if (currSum > sum)
                    j--;
                else
                    k++;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline after the integer input
    while (t--) {
        string input;
        getline(cin, input);

        stringstream ss(input);
        vector<int> arr;
        int num;
        while (ss >> num)
            arr.push_back(num);

        Solution obj;
        if (obj.findTriplets(arr))
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }

    return 0;
}

// } Driver Code Ends