//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findMissing(vector<int> &arr) {
        int n = arr.size();
        int a = arr[0];
        int b = arr[1];
        int d = b-a;
        for(int i = 0 ; i < n ; i++)
        {
            if(a+i*d != arr[i])
                return a+i*d;
        }
        return a + n*d;
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
        cout << ob.findMissing(arr) << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends