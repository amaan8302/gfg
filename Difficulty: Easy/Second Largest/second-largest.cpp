//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // Code Here
        int largest = INT_MIN, secondLargest = INT_MIN;

        for (int i : arr) 
        {
            if (i > largest) 
            {
                secondLargest = largest;
                largest = i;
            } else if (i > secondLargest && i < largest) {
                secondLargest = i;
            }
        }
    
        return (secondLargest == INT_MIN) ? -1 : secondLargest;
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
        int ans = ob.getSecondLargest(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends