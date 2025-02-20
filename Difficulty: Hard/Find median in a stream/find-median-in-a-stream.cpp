//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) 
    {
        priority_queue<int>left;
        priority_queue<int,vector<int>,greater<int>>right;
        vector<double>ans;
        for(int i = 0 ; i < arr.size() ; i++)
        {
            left.push(arr[i]);
            int ele = left.top();
            right.push(ele);
            left.pop();
            if(right.size()>left.size())
            {
                int ele = right.top();
                left.push(ele);
                right.pop();
            }
            double median;
            if(left.size() != right.size())
                median = left.top();
            else
                median = (double)(left.top()+right.top())/2; 
            ans.push_back(median);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<double> ans = ob.getMedian(nums);
        cout << fixed << setprecision(1);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends