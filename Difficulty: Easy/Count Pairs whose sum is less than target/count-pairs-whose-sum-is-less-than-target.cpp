//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int countPairs(vector<int> &arr, int target)
    {
        std::sort(arr.begin(), arr.end());
        int i = 0, j = arr.size() - 1;
        int cnt = 0; 
        while (i < j) {
            int sum = arr[i] + arr[j];
            if (sum >= target)
                j--;
            else
            {
                cnt += (j - i);
                // cnt++;
                i++;
            }
        }
        return cnt;
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
        int target;
        cin >> target;
        cin.ignore();
        Solution ob;
        int res = ob.countPairs(arr, target);
        cout << res << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends