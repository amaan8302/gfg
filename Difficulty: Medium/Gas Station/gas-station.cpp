//{ Driver Code Starts
// C++ program to find union of
// two sorted arrays
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        int tg=0,tc=0,n=gas.size();
        for(int i = 0 ; i < n ; i++)
        {
            tg+=gas[i];
            tc+=cost[i];
        }
        if(tc>tg)
            return -1;
        int i = 0,start=0,diff = 0;
        while(i<n)
        {
            diff += (gas[i]-cost[i]);
            if(diff<0)
            {
                start = i+1;
                diff = 0;
            }
            i++;
        }
        return start;
    }
};



//{ Driver Code Starts.
/* Driver program to test above function */
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    while (t--) {

        vector<int> gas, cost;
        string input1;
        getline(cin, input1);
        stringstream ss(input1);
        int number1;
        while (ss >> number1) {
            gas.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream sss(input2);
        int number2;
        while (sss >> number2) {
            cost.push_back(number2);
        }
        Solution ob;
        int ans = ob.startStation(gas, cost);

        cout << ans << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends