//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    int longestSubsequence(int n, int a[])
    {
        
        std::vector<int> dp;
    
        for (int i = 0; i < n; i++) {
            auto it = std::lower_bound(dp.begin(), dp.end(), a[i]);
            
            if (it == dp.end()) {
                dp.push_back(a[i]);
            } else {
                *it = a[i];
            }
        }
        
        return dp.size();
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends