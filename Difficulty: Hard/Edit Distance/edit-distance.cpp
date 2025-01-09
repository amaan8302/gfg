//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to compute the edit distance between two strings
    int editDistance(string& a, string& b) {
        // code here
        if(a.length()==0)
            return b.length();
        if(b.length()==0)
            return a.length();
        vector<int>curr(b.size()+1,0);
        vector<int>next(b.size()+1,0);
        for(int i = 0 ; i < b.length();i++)
            next[i]=b.length()-i;
        for(int i = a.length()-1; i>=0 ;i--)
        {
            for(int j = b.length()-1 ; j>=0 ; j--)
            {
                curr[b.length()]=a.length()-i;  //second base case ki handling
                if(a[i]==b[j])
                    curr[j] = next[j+1];
                else
                {
                    int insertion,deletion,replace;
                    //insert
                    insertion = 1 + curr[j+1];
                    //deletion
                    deletion = 1 + next[j];
                    //replacement
                    replace = 1 + next[j+1];
                    curr[j] = min(insertion,min(deletion, replace));
                }
            }
            next=curr;
        }
        return next[0];
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        string s1;
        getline(cin, s1);
        string s2;
        getline(cin, s2);
        Solution ob;
        int ans = ob.editDistance(s1, s2);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends