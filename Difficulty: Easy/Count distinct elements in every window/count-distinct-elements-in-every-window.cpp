//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        unordered_map<int,int>freq;
        int i = 0;
        int j = 0;
        int n = arr.size();
        vector<int>res;
        int cnt = 0;
        while(j<n)
        {
            while(j-i <= k-1)
            {
                if(freq[arr[j]]==0)
                {
                    cnt++;
                    freq[arr[j]]++;
                }
                else
                    freq[arr[j]]++;
                j++;
            }
            res.push_back(cnt);
            if(freq[arr[i]]>1)
                freq[arr[i]]--;
            else
            {
                cnt--;
                freq[arr[i]]--;
            }
            i++;
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution obj;
        vector<int> res = obj.countDistinct(arr, k);
        for (auto it : res)
            cout << it << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends