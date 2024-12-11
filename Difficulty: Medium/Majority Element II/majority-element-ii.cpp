//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findMajority(vector<int>& arr) {
        unordered_map<int,int>freq;
        vector<int>res;
        for(int i : arr)
            freq[i]++;
        for (const auto& pair : freq) 
        {
            if(pair.second > arr.size()/3)
                res.push_back(pair.first);
        }
        std::sort(res.begin(),res.end());
        if(res.empty())
            return {};
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<int> ans = ob.findMajority(nums);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto &i : ans)
                cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends