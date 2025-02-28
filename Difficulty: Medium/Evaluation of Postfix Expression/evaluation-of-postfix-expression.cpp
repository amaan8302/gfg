//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int evaluate(vector<string>& arr) {
        stack<int>s;
        for(string &i : arr)
        {
            if(i=="+" || i=="*"||i=="-"||i=="/")
            {
                int b = s.top();
                s.pop();
                int a = s.top();
                s.pop();
                int res;
                if(i=="+")
                    res = a+b;
                else if(i=="-")
                    res = a-b;
                else if(i=="*")
                    res = a*b;
                else if(i=="/")
                    res = a/b;
                s.push(res);
            }
            else
            s.push(stoi(i));
        }
        return s.top();
    }
};


//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<string> arr;
        while (ss >> str) {
            arr.push_back(str);
        }
        Solution ob;
        cout << ob.evaluate(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends