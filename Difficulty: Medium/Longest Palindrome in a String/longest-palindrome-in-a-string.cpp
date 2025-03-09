//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string expandAroundCenter(string s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return s.substr(left + 1, right - left - 1);
    }
    string longestPalindrome(string &s) {
        int n = s.length();
        if (n == 0) return "";
        string longest = "";
        for (int i = 0; i < n; i++) {
            string oddPal = expandAroundCenter(s, i, i);
            if (oddPal.length() > longest.length()) {
                longest = oddPal;
            }

            string evenPal = expandAroundCenter(s, i, i + 1);
            if (evenPal.length() > longest.length()) {
                longest = evenPal;
            }
        }

        return longest;
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
        cout << ob.longestPalindrome(S) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends