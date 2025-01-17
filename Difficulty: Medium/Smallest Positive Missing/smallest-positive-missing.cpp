//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool bs(vector<int> &arr , int target)
    {
        int low = 0,high = arr.size()-1;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(arr[mid]==target)
                return 1;
            else if(arr[mid]>target)
                high = mid-1;
            else
                low = mid+1;
        }
        return false;
    }
    int missingNumber(vector<int> &arr) {
        std::sort(arr.begin(),arr.end());
        for(int i = 1 ; i <= 1e5 ; i++)
        {
            if(!bs(arr,i))
                return i;
        }
        return 0;
    }
};

//{ Driver Code Starts.

// int missingNumber(int arr[], int n);

int main() {

    // taking testcases
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
        int result = ob.missingNumber(arr);
        cout << result << "\n";
    }
    return 0;
}
// } Driver Code Ends