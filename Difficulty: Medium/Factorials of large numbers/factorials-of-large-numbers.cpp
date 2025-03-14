//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void multiply(vector<int>& v, int num) 
    {
        int carry = 0;
        for (int i = v.size() - 1; i >= 0; i--) {
            int prod = v[i] * num + carry;
            v[i] = prod % 10;
            carry = prod / 10;
        }
        while (carry) {
            v.insert(v.begin(), carry % 10);
            carry /= 10;
        }
    }
    
    vector<int> factorial(int n) {
        vector<int> arr = {1};
        for (int i = 2; i <= n; i++)
            multiply(arr, i);
        return arr;
    }

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i) {
            cout << result[i] << " ";
        }
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends