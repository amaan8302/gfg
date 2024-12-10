//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Complete back-end function template for C++


// } Driver Code Ends
// User function template for C++

class Solution {
public:
    vector<long long> productExceptSelf(vector<int>& arr) {
        int n = arr.size();
        vector<long long> res(n, 1);

        long long prefix = 1, suffix = 1;
        for (int i = 0; i < n; i++) {
            res[i] *= prefix;
            prefix *= arr[i];
        }
        for (int i = n - 1; i >= 0; i--) {
            res[i] *= suffix;
            suffix *= arr[i];
        }
        return res;
    }
};



//{ Driver Code Starts.

int main() {

    int t; // Number of test cases
    cin >> t;
    cin.ignore(); // To ignore newline character after t input

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        while (ss >> number) {
            arr.push_back(number);
        }

        Solution obj;
        vector<long long> vec = obj.productExceptSelf(arr); // Function call

        for (int i = 0; i < vec.size(); i++) { // Print the output
            cout << vec[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends