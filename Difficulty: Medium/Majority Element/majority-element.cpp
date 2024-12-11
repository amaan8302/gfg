//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int majorityElement(vector<int>& nums) {

        int cnt=0;
        int ele;
        for(int i = 0;i<nums.size();i++)
        {
            if(cnt==0)
            {
                cnt=1;
                ele=nums[i];
            }
            else if(nums[i]==ele)
                cnt++;
            else
                cnt--;
        }
        int cnt1=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==ele)
                cnt1++;
        }
        if(cnt1>(nums.size()/2))
            return ele;
        return -1;
        // your code here
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        vector<int> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.majorityElement(a) << endl;
    }

    return 0;
}

// } Driver Code Ends