//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isParenthesisBalanced(string& s) 
{
    stack<char> res;
    for (char ch : s)
    {
        switch (ch)
        {
            case '(':
            case '{':
            case '[':
                res.push(ch);
                break;

            case ')':
                if (res.empty() || res.top() != '(')
                    return false;
                res.pop();
                break;

            case '}':
                if (res.empty() || res.top() != '{')
                    return false;
                res.pop();
                break;

            case ']':
                if (res.empty() || res.top() != '[')
                    return false;
                res.pop();
                break;

            default:
                return false;
        }
    }
    return res.empty();
}

};

//{ Driver Code Starts.

int main() {
    int t;
    string a;
    cin >> t;
    while (t--) {
        cin >> a;
        Solution obj;
        if (obj.isParenthesisBalanced(a))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends