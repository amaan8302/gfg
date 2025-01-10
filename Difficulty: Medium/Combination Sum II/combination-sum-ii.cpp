//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void solve(vector<int> &arr, int target,vector<int>&curr, int index ,vector<vector<int>>&res)
    {
        if(target<0)
            return;
        if(target==0) {res.push_back(curr); return;}
        for(int i = index ; i < arr.size() ; i++)
        {
            if(i>index && arr[i]==arr[i-1])
                continue;
            curr.push_back(arr[i]);
            solve(arr,target-arr[i],curr,i+1,res);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &arr, int target) {
        std::sort(arr.begin(),arr.end());
        vector<vector<int>>res;
        vector<int>curr;
        solve(arr, target, curr, 0, res);
        return res;
    }
};

//{ Driver Code Starts.
int main() {

    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> candidates(n);
        for (int i = 0; i < n; ++i) {
            cin >> candidates[i];
        }
        // char marker;
        // cin >> marker;

        Solution obj;

        vector<vector<int>> comb = obj.combinationSum2(candidates, k);
        sort(comb.begin(), comb.end());
        cout << "[ ";
        for (int i = 0; i < comb.size(); i++) {
            cout << "[ ";
            for (int j = 0; j < comb[i].size(); j++) {
                cout << comb[i][j] << " ";
            }
            cout << "]";
        }
        cout << " ]\n";

        // cout << "\n~\n";
    
cout << "~" << "\n";
}
    fclose(stdout);
    return 0;
}

// } Driver Code Ends