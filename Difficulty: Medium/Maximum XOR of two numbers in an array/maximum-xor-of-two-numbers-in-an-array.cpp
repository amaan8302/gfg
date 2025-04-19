//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class TrieNode {
public:
    TrieNode* children[2];
    TrieNode() {
        children[0] = nullptr;
        children[1] = nullptr;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }

    void insert(int num) {
        TrieNode* node = root;
        for (int i = 31; i >= 0; --i) {
            int bit = (num >> i) & 1;
            if (node->children[bit] == nullptr) {
                node->children[bit] = new TrieNode();
            }
            node = node->children[bit];
        }
    }

    int getMaxXOR(int num) {
        TrieNode* node = root;
        int maxXOR = 0;
        for (int i = 31; i >= 0; --i) {
            int bit = (num >> i) & 1;
            int oppositeBit = bit ^ 1;
            if (node->children[oppositeBit] != nullptr) {
                maxXOR = (maxXOR << 1) | 1;
                node = node->children[oppositeBit];
            } else {
                maxXOR = (maxXOR << 1);
                node = node->children[bit];
            }
        }
        return maxXOR;
    }
};

class Solution {
  public:
    int maxXor(vector<int> &nums) {
        Trie trie;
        for (int num : nums) {
            trie.insert(num);
        }

        int maxResult = 0;
        for (int num : nums) {
            maxResult = max(maxResult, trie.getMaxXOR(num));
        }

        return maxResult;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.maxXor(arr) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends