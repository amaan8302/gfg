//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool isPossible(vector<int> &v, int k,int mid)
    {
        int cow = 1;
        int lastPos=v[0];
        for(int i : v)
        {
            if(i - lastPos>=mid)
            {
                cow++;
                if(cow==k)
                    return true;
                lastPos=i;
            }
        }
        return false;
    }
    int aggressiveCows(vector<int> &v, int k) {
        sort(v.begin(),v.end());
        int low = 0;
        int ans = -1;
        for(int i : v)
            ans = max(ans,i);
        int high = ans;
        int res = -1;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(isPossible(v,k,mid))
            {
                res = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends