//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int canReach(int A[], int N) {
    int maxReach = 0; // Tracks the farthest index we can reach

    for (int i = 0; i < N; i++) {
        if (i > maxReach) {
            return 0; // If current index is beyond the farthest reachable point
        }
        maxReach = std::max(maxReach, i + A[i]); // Update maxReach
        if (maxReach >= N - 1) {
            return 1; // If we can reach or exceed the last index
        }
    }
    return 0;
}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.canReach(A,N) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends