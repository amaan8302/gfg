//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool solve(vector<int>& arr, int x)
    {
        int low = 0;
        int high = arr.size()-1;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            if(arr[mid]==x)
                return 1;
            if(arr[mid]<x)
                low = mid+1;
            else
                high = mid - 1;
        }
        return false;
    }
    int missingNumber(vector<int>& arr) {
        // Code here
        int ans = -1;
        for(int i = 1 ; i <= arr.size() ; i++)
        {
            if(!solve(arr,i))
            {
                ans = i;
                break;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int ans = obj.missingNumber(arr);
        cout << ans << endl;
        // cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends