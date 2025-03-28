//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    typedef pair<int,int>p;
    int activitySelection(vector<int> &start, vector<int> &finish) {
        vector<p>arr;
        int n = start.size();
        for(int i = 0 ; i < n ; i++)
            arr.push_back({finish[i],start[i]});
        std::sort(arr.begin(), arr.end());
        int currFinish = arr[0].first;
        int i = 1,cnt=1;
        while( i < n)
        {
            if(arr[i].second > currFinish)
            {
                cnt++;
                currFinish = arr[i].first;
            }
            i++;
        }
        return cnt;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        vector<int> start;
        int num;
        while (ss >> num)
            start.push_back(num);
        getline(cin, input);
        ss.clear();
        vector<int> finish;
        ss.str(input);
        while (ss >> num)
            finish.push_back(num);

        Solution obj;
        cout << obj.activitySelection(start, finish) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends