//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<vector<int>> distinctPairs(vector<int> &arr, int target)
    {
        unordered_map<int, int> freq;
        set<pair<int, int>> res;
    
        for (int i : arr)
            freq[i]++;
    
        for (int i : arr) {
            int x = target - i;
            if (freq[x]) {
                if (i == x && freq[i] < 2) continue;
                res.insert({min(i, x), max(i, x)});
            }
        }
    
        vector<vector<int>> ans;
        for (auto &p : res)
            ans.push_back({p.first, p.second});
    
        return ans;
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

        vector<vector<int>> res = ob.distinctPairs(arr, target);

        if (res.size() == 0) {
            cout << "[]\n";
        }
        for (int i = 0; i < res.size(); i++) {
            for (int j = 0; j < res[i].size(); j++) {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends