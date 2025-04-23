//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int getSingle(vector<int> &arr) 
    {
        set<int>st(arr.begin(),arr.end());
        unordered_map<int,int>freq;
        int ans=0;
        for(int i : arr)
            freq[i]++;
        while (!st.empty()) 
        {
            int val = *st.begin();
            st.erase(st.begin());
            if(freq[val]==1)
                ans = val;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.getSingle(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends