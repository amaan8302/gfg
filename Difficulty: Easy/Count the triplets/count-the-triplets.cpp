//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int countTriplet(vector<int>& arr) {
        std::sort(arr.begin(), arr.end()); 
        int cnt = 0;
        int n = arr.size();
    
        for (int i = n - 1; i >= 2; i--) {
            int target = arr[i];
            int low = 0;
            int high = i - 1; 
    
            while (low < high) {
                if (arr[low] + arr[high] == target) {
                    cnt++;
                    low++;
                    high--;
                } else if (arr[low] + arr[high] < target) {
                    low++;
                } else {
                    high--;
                }
            }
        }
    
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.countTriplet(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends