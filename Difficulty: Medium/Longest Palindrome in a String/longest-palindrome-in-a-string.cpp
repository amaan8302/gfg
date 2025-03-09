//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int leng(int left, int right , string &s)
    {
        int len = 0;
        while(left>=0 && right < s.length())
        {
            if(s[left]==s[right])
            {
                len+=2;left--;right++;
            }
            else
                break;
        }
        return len;
    }
    string longestPalindrome(string &s) {
        int n = s.length();
        int maxLen = 1,start = 0;
        for(int i =  0 ; i < n ; i++)
        {
            int len = 1 + leng(i-1,i+1,s);
            if(len>maxLen){
            maxLen = len;
            start = i - len/2;}
        }
        for(int i =  1 ; i < n ; i++)
        {
            int len = leng(i-1,i,s);
            if(len>maxLen){
            maxLen = len;
            start = i - len/2;}
        }
        return s.substr(start , maxLen);
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