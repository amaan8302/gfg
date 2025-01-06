//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        int n = arr.size();
        if (n < 2) return {}; 
        std::sort(arr.begin(), arr.end());
        int closestDiff = INT_MAX; 
        int maxAbsDiff = INT_MIN; 
        vector<int> result;
        int i = 0, j = n - 1;
        while (i < j) {
            int sum = arr[i] + arr[j];
            int diff = abs(sum - target);
            if (diff < closestDiff || (diff == closestDiff && (arr[j] - arr[i] > maxAbsDiff))) {
                closestDiff = diff;
                maxAbsDiff = arr[j] - arr[i];
                result = {arr[i], arr[j]};
            }
            if (sum < target)
                i++;
            else
                j--;
        }
        return result;
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
        string ks;
        getline(cin, ks);
        int target = stoi(ks);
        Solution ob;
        vector<int> ans = ob.sumClosest(arr, target);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto it : ans) {
                cout << it << " ";
            }
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends