//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // bool isSubsetSum(vector<int>& arr, int s)
    // {
    //     int n = arr.size();
    //     vector<vector<bool>>dp(arr.size()+1,vector<bool>(s+1,0));
    //     for(int i = 0 ; i <= arr.size() ; i++)
    //         dp[i][0]=true;
    //     for(int i = n-1 ; i >= 0 ; i--)
    //     {
    //         for(int sum = 0 ; sum <=s ; sum++)
    //         {
    //             bool take=false;
    //             if(sum>=arr[i])
    //                 take = dp[i+1][sum - arr[i]];
    //             bool notake = dp[i+1][sum];
    //             dp[i][sum] = take || notake;
    //         }
    //     }
    //     return dp[0][s];
    // }
    bool isSubsetSum(vector<int>& arr, int s)
    {
        int n = arr.size();
        vector<bool>curr(s+1,false);
        vector<bool>next(s+1,false);
        next[0]=true;
        for(int i = n-1 ; i >= 0 ; i--)
        {
            for(int sum = 0 ; sum <=s ; sum++)
            {
                bool take=false;
                if(sum>=arr[i])
                    take = next[sum - arr[i]];
                bool notake = next[sum];
                curr[sum] = take || notake;
            }
            next = curr;
        }
        return curr[s];
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
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends