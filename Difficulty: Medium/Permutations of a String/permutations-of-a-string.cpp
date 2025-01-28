//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void solve(int i , int n , string &s , string &per, unordered_set<string>&set)
    {
        if(per.size()==n)
        {
            set.insert(per);
            return;
        }
        for(int j = i ; j<n;j++)
        {
            swap(s[i],s[j]);
            per.push_back(s[i]);
            solve(i+1,n,s,per,set);
            per.pop_back();
            swap(s[i],s[j]);
        }
    }
    vector<string> findPermutation(string &s) {
        unordered_set<string>set;
        string per;
        int n = s.size();
        solve(0,n,s,per,set);
        vector<string>res(set.begin(),set.end());
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends