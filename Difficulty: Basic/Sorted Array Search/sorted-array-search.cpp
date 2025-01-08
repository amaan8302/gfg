//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool searchInSorted(vector<int>& arr, int k) {
        int n = arr.size();
        int low = 0;
        int high = n-1;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(arr[mid]==k)
                return 1;
            else if(arr[mid]>k)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return 0;
    }
};

//{ Driver Code Starts.

int main(void) {

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

        int k;
        cin >> k;
        cin.ignore();
        Solution ob;
        cout << (ob.searchInSorted(arr, k) ? "true" : "false") << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends