//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++
struct Node {
    bool isEnd;
    Node* alphabets[26];
    Node() {
        isEnd = false;
        for (int i = 0; i < 26; i++)
            alphabets[i] = NULL;
    }
};
class Trie {
public:
    Node* root;

    Trie() {
        root = new Node();
    }

    void insertUtil(Node* root, string word) {
        if (word.length() == 0) {
            root->isEnd = true;
            return;
        }
        int index = word[0] - 'a';
        if (root->alphabets[index] == NULL)
            root->alphabets[index] = new Node();
        insertUtil(root->alphabets[index], word.substr(1));
    }

    void insert(string &word) {
        insertUtil(root, word);
    }

    bool searchUtil(Node* root, string word) {
        if (word.length() == 0)
            return root->isEnd;
        int index = word[0] - 'a';
        if (root->alphabets[index] == NULL)
            return false;
        return searchUtil(root->alphabets[index], word.substr(1));
    }

    bool search(string &word) {
        return searchUtil(root, word);
    }

    bool prefixUtil(Node* root, string word) {
        if (word.length() == 0)
            return true;
        int index = word[0] - 'a';
        if (root->alphabets[index] == NULL)
            return false;
        return prefixUtil(root->alphabets[index], word.substr(1));
    }

    bool isPrefix(string &prefix) {
        return prefixUtil(root, prefix);
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int q;
        cin >> q;
        cin.ignore();
        vector<bool> ans;
        Trie ob;
        for (int i = 0; i < q; i++) {
            int x;
            cin >> x;
            string s;
            cin >> s;
            cin.ignore();
            if (x == 1) {
                ob.insert(s);
            } else if (x == 2) {
                ans.push_back(ob.search(s));
            } else if (x == 3) {
                ans.push_back(ob.isPrefix(s));
            }
        }
        cout << boolalpha;
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends