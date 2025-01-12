//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> getRightArray(vector<int>&arr, int n)
    {
        vector<int>left(n);
        left[n-1]=arr[n-1];
        for(int i = n-2 ; i >= 0 ; i--)
            left[i]=max(left[i+1],arr[i]);
        return left;
    }
    vector<int> getLeftArray(vector<int>&arr, int n)
    {
        vector<int>left(n);
        left[0]=arr[0];
        for(int i = 1 ; i < n ; i++)
            left[i]=max(left[i-1],arr[i]);
        return left;
    }
    int maxWater(vector<int> &height) {
        int n = height.size();
        vector<int>left = getLeftArray(height,n);
        vector<int>right = getRightArray(height,n);
        int sum = 0;
        for(int i = 0 ; i < n ; i++)
            sum += min(left[i],right[i])-height[i];
        return sum;
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends