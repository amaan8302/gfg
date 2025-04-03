//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    int maxStairHeight(int N) {
        return (int)((-1 + sqrt(1 + 8LL * N)) / 2);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.maxStairHeight(N) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends