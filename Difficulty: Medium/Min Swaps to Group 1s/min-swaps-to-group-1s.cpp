//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minSwaps(vector<int>& arr) {
        int i = 0;
        int j = 0;
        int maxi = 0;
        int size = 0;
        for(int i : arr)
        {
            if(i==1)
                size++;
        }
        if(size==0)
            return -1;
        int n = arr.size();
        int x = 0;
        while(j<=n)
        {
            if(j - i + 1 <= size)
            {
                if(arr[j]==1)
                    x++;
                j++;
            }
            else
            {
                maxi = max(maxi , x);
                if(arr[i]==1)
                    x--;
                i++;
            }
        }
        return size - maxi;
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        cout << ob.minSwaps(nums) << endl;
    }
    return 0;
}

// } Driver Code Ends