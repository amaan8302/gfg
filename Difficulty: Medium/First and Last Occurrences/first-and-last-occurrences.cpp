//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int first(vector<int>& arr, int x)
    {
        int low = 0;
        int high = arr.size()-1;
        int ans = -1;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(arr[mid]>=x)
            {
                if(arr[mid] == x) ans = mid;
                high = mid - 1;
            }
            else
            {    
                low = mid + 1;
            }
        }
        return ans;
    }
    int last(vector<int>& arr, int x)
    {
        int low = 0;
        int high = arr.size()-1;
        int ans = -1;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(arr[mid]<=x)
            {
                if(arr[mid] == x) ans = mid;
                low = mid + 1;
            }
            else
            {   
                high = mid - 1;
            }
        }
        return ans;
    }
    vector<int> find(vector<int>& arr, int x) {
        return {first(arr,x),last(arr,x)};
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
        int x;
        cin >> x;
        cin.ignore();
        vector<int> ans;
        Solution ob;
        ans = ob.find(arr, x);
        cout << ans[0] << " " << ans[1] << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends