//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    typedef pair<int,int>p;
    int findPlatform(vector<int>& start, vector<int>& finish) 
    {
        std::sort(start.begin(),start.end());
        std::sort(finish.begin(),finish.end());
        int n = start.size(), i = 0, j = 0,maxi=INT_MIN;
        int cnt = 0;
        while(i < n && j < n)
        {
            if(start[i]<=finish[j])
            {
                cnt++;
                i++;
            }
            else
            {
                cnt--;
                j++;
            }
            maxi = max(maxi,cnt);
        }
        maxi = max(maxi,cnt);
        return maxi;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr, dep;
        string input;

        // Read first array (arr)
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        // Read second array (dep)
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            dep.push_back(number);
        }

        // Assuming Solution class is defined elsewhere with a method findPlatform
        Solution ob;
        cout << ob.findPlatform(arr, dep);

        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends