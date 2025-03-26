//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool solve(int n, string &s , set<string>&st , int i,vector<int>&dp)
    {
        if(i>=n)
            return 1;
        if(dp[i]!=-1)
            return dp[i];
        string temp = "";
        for(int x = i ; x < n ; x++){
            temp+=s[x];
            if(st.find(temp)!=st.end())
            {
                if(solve(n,s,st,x+1,dp))
                    return dp[i] = 1;
            }
        }
        return dp[i] = 0;
    }
    bool wordBreak(string &s, vector<string> &dictionary) {
        int n = s.size();
        vector<int>dp(n+1,-1);
        set<string>st(dictionary.begin(),dictionary.end());
        return solve(n,s,st,0,dp);
    }
};


//{ Driver Code Starts.

vector<string> inputLine() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    vector<string> res;
    while (ss >> str) {
        res.push_back(str);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        cin >> s;
        cin.ignore();
        vector<string> dictionary = inputLine();

        Solution ob;
        if (ob.wordBreak(s, dictionary)) {
            cout << "true\n";
        } else
            cout << "false\n";
        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends