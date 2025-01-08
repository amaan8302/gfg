//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countTriangles(vector<int>& nums) {
        // std::sort(arr.begin(),arr.end());
        // int n = arr.size();
        // int tri = 0;
        // for(int idx = 0 ; idx < n-2 ; idx++)
        // {
        //     int i = idx+1;
        //     int j = n-1;
        //     int target = arr[idx];
        //     while(i<j)
        //     {
        //         int sum = arr[i]+arr[j];
        //         if(sum >= target)
        //         {
        //             tri++;
        //             j--;
        //         }
        //         if (sum < target)
        //             i++;
        //     }
        // }
        // return tri;
        int n = nums.size();
        int count = 0;
        sort(nums.begin(), nums.end());
        for (int i = n - 1; i >= 2; i--) {
            int left = 0;
            int right = i - 1;

            while (left < right) {
                if (nums[left] + nums[right] > nums[i]) {
                    count += (right - left);
                    right--;
                } else {
                    left++;
                }
            }
        }
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline after the integer input
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
        cout << obj.countTriangles(a) << "\n~\n";
    }

    return 0;
}

// } Driver Code Ends