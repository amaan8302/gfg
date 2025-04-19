//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findDuplicate(vector<int>& arr) {
        unordered_map<int,bool>map;
        int ans = 0;
        for(int i : arr)
        {
            if(!map[i])
                map[i]=1;
            else
                ans = i;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int test_cases;
    cin >> test_cases;
    cin.ignore();
    while (test_cases--) {
        string input;
        vector<int> arr;

        // Read the array from input line
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        // Solution instance to invoke the function
        Solution ob;
        int result = ob.findDuplicate(arr);

        cout << (result) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends