//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findSubString(string& s) {
        unordered_set<char> uniqueChars(s.begin(), s.end());
        int required = uniqueChars.size();
        unordered_map<char, int> windowFreq;
        int i = 0, j = 0, formed = 0, minLen = INT_MAX;
        while (j < s.length()) {
            windowFreq[s[j]]++;
            if (windowFreq[s[j]] == 1) formed++;
    
            while (formed == required) {
                minLen = min(minLen, j - i + 1);
                windowFreq[s[i]]--;
                if (windowFreq[s[i]] == 0) formed--;
                i++;
            }
            j++;
        }
        return minLen;
    }
};


//{ Driver Code Starts.
//      Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends