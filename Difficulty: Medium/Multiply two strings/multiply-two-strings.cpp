//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string multiplyStrings(string& s1, string& s2) 
    {
        auto removeLeadingZeros = [](string &s) {
        int i = 0;
        while (i < s.size() - 1 && s[i] == '0') i++;
        s = s.substr(i);
    };
    
    bool neg = false;
    if (s1[0] == '-') {
        neg = !neg;
        s1 = s1.substr(1);
    }
    if (s2[0] == '-') {
        neg = !neg;
        s2 = s2.substr(1);
    }

    removeLeadingZeros(s1);
    removeLeadingZeros(s2);

    if (s1 == "0" || s2 == "0") return "0";

    int n = s1.size(), m = s2.size();
    string res(n + m, '0');

    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            int mul = (s1[i] - '0') * (s2[j] - '0');
            int sum = (res[i + j + 1] - '0') + mul;
            res[i + j + 1] = (sum % 10) + '0';
            res[i + j] += sum / 10;
        }
    }

    int i = 0;
    while (i < res.size() && res[i] == '0') i++;

    string ans = res.substr(i);
    if (neg) ans = '-' + ans;
    return ans;

    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string a;
        string b;
        cin >> a >> b;
        Solution obj;
        cout << obj.multiplyStrings(a, b) << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends