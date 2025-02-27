//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        int n = arr.size();
        vector<bool>seen(n+1,0);
        for(int i = 0 ; i < n ; i++){
            if(arr[i]>=0 && arr[i]<=n+1)
                seen[arr[i]]=true;
        }
        for(int i = 1 ; i<=n;i++)
        {
            if(seen[i]==false)
                return i;
        }
        return n+1;
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