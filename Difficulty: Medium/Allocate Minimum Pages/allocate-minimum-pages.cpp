//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isPossible(vector<int>& arr, int n, int m,int mid)
    {
        int student = 1;
        int pages = 0;
        for(int i : arr)
        {
            if(i>mid) return 0;
            if(i + pages <= mid)
                pages = pages + i;
            else
            {
                student++;
                if(student>m)
                    return false;
                pages = i;
            }
        }
        return true;
    }
    int findPages(vector<int> &arr, int m) {
        // code here
        int n = arr.size();
        if(n<m)
            return -1;
        int sum=0;
        for(int i : arr)
            sum = sum + i;
        int low = 0;
        int high = sum;
        int ans=-1;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(isPossible(arr,n,m,mid))
            {
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.findPages(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends