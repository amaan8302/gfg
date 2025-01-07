//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        int n = arr.size();
        int pairs = 0;
        if(n<=1)
            return 0;
        if(n==2 && arr[0]+arr[1]==target)
            return 1;
        int i = 0;
        int j = n-1;
        while(i<j)
        {
            int sum = arr[i]+arr[j];
            if(sum>target)
                j--;
            else if(sum<target)
                i++;
            else
            {
                int start = 0;
                int end = 0;
                int k = i;
                int l = j;
                int Estart = arr[i];
                int eEnd = arr[j];
                while(arr[i]==Estart && i<=j)
                {
                    start++;
                    i++;
                }
                while(arr[j]==eEnd && i<=j)
                {
                    end++;
                    j--;
                }
                if(Estart==eEnd)
                    pairs += start*(start-1)/2;
                else
                    pairs += end*start;
            }
        }
        return pairs;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        int target;
        string input;
        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        cin >> target;
        cin.ignore();
        Solution obj;
        cout << obj.countPairs(arr, target) << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends