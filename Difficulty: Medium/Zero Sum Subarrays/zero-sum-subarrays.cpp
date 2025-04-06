//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findSubarray(vector<int> &arr) {
        unordered_map<int,int>freq;
        freq[0]=1;
        int sum = 0;
        int n = arr.size();
        int cnt = 0;
        for(int i = 0 ; i < n ; i++)
        {
            sum += arr[i];
            if(freq.find(sum)!=freq.end())
               cnt +=freq[sum];
            freq[sum]++;
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
        int num;
        vector<int> arr;
        while (ss >> num)
            arr.push_back(num);

        Solution ob;
        cout << ob.findSubarray(arr) << endl;
        cout << "~\n";
    }
}

// } Driver Code Ends