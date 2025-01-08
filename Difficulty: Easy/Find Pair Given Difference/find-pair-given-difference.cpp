//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    bool bs(vector<int> &arr, int x, int excludeIndex)
    {
        int low = 0;
        int high = arr.size() - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid] == x && mid != excludeIndex)
                return true;
            else if (arr[mid] > x)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return false;
    }
    bool findPair(vector<int> &arr, int x) {
        std::sort(arr.begin(), arr.end());
        int n = arr.size();
        if (n <= 1)
            return false;
    
        for (int i = 0; i < n; i++)
        {
            int target = x + arr[i];
            if (bs(arr, target, i))
                return true;
        }
        return false;
    }


};


//{ Driver Code Starts.

int main() {

    int t;
    scanf("%d ", &t);

    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int k;
        scanf("%d ", &k);
        Solution obj;

        cout << (obj.findPair(arr, k) ? "true" : "false") << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends