//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    long long solve(string &s , int i, int j , int isTrue,vector<vector<vector<int>>>&dp)
    {
        if(i>j)
            return false;
        if(i==j){
            if(isTrue)  
                return s[i] == 'T';
            else
                return s[i] == 'F';
        }
        if(dp[i][j][isTrue]!=-1)
            return dp[i][j][isTrue];
        long long ways = 0;
        for(int x = i+1 ; x<j ; x+=2)
        {
            long long lt = solve(s,i,x-1,1,dp);
            long long lf = solve(s,i,x-1,0,dp);
            long long rt = solve(s,x+1,j,1,dp);
            long long rf = solve(s,x+1,j,0,dp);
            
            if(s[x]=='&')
            {
                if(isTrue)
                    ways = (ways+(rt*lt));
                else
                    ways = (ways+(rt*lf) + (lt*rf) + (rf*lf));
            }
            else if(s[x]=='|')
            {
                if(isTrue)
                    ways = (ways+(rt*lt) + (lt*rf) +(rt*lf));
                else
                    ways = (ways+(rf*lf));
            }
            else
            {
                if(isTrue)
                    ways = (ways+(rf*lt) + (lf*rt));
                else
                    ways = (ways+(lt*rt) + (lf*rf));
            }
        }
        return dp[i][j][isTrue] = ways;
    }
    int countWays(string &s) {
        vector<vector<vector<int>>>dp(s.size()+1,vector<vector<int>>(s.size()+1,vector<int>(3,-1)));
        return solve(s,0,s.size()-1,1,dp);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        int ans = ob.countWays(s);
        cout << ans << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends