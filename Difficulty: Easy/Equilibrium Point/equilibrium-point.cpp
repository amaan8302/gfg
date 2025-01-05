//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int equilibriumPoint(vector<int> &arr) {
        int n = arr.size();
        if(n==1)
            return 1;
        int sum = 0;
        for(int i : arr)
            sum+=i;
        int x = arr[0];
        int ans = -1;
        for(int i = 1 ; i < arr.size() ; i++)
        {
            if(x == sum - x - arr[i])
                ans = i+1;
            x+=arr[i];
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    while (t--)   // while testcases exist
    {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.equilibriumPoint(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends