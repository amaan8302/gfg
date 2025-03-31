//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxPartitions(string &s) {
        if (s.empty()) return 0;
    
    // Store the last occurrence of each character
        unordered_map<char, int> lastPos;
        for (int i = 0; i < s.length(); i++) {
            lastPos[s[i]] = i;
        }
        
        int count = 0;        // Number of partitions
        int start = 0;         // Start position of current partition
        int end = 0;           // End position of current partition
        
        while (start < s.length()) {
            // Initialize end as the last occurrence of the first character in this partition
            end = lastPos[s[start]];
            
            // Extend the partition if needed
            int i = start;
            while (i <= end) {
                // If we find a character that extends beyond our current end,
                // we need to include it in the current partition
                end = max(end, lastPos[s[i]]);
                i++;
            }
            
            // Found a valid partition
            count++;
            
            // Start a new partition
            start = end + 1;
        }
        
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;

    for (int i = 0; i < tc; ++i) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.maxPartitions(s) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends