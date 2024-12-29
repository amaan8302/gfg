//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    bool bs(vector<int>& arr , int target)
    {
        int low = 0;
        int high = arr.size()-1;
        while(low <= high)
        {
            int mid = low + (high-low)/2;
            if(arr[mid]==target)
                return true;
            else if(arr[mid]>target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return false;
    }
    int missingNumber(vector<int>& arr) {
        std::sort(arr.begin(),arr.end());
        int n = arr.size() , ans;
        for(int i = 1 ; i<=n+1 ; i++)
        {
            if(bs(arr,i)==false)
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
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.missingNumber(a) << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends