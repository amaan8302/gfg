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
                len++;left--;right++;
            }
            else
                break;
        }
        return len;
    }
    int countPS(string &s) {
        int n = s.length();
        int oc = 0, ec=0;
        for(int i =  0 ; i < n ; i++)
        {
            oc += leng(i-1,i+1,s);
        }
        for(int i =  1 ; i < n ; i++)
        {
            ec += leng(i-1,i,s);
        }
        return oc+ec;        
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
        cout << ob.countPS(s) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends