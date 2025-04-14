//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string findOrder(vector<string> &words) {
    unordered_map<char, vector<char>> graph;
    unordered_map<char, int> inDegree;
    
    for (const string &word : words)
        for (char c : word)
            inDegree[c] = 0;

    for (int i = 0; i < words.size() - 1; ++i) {
        string w1 = words[i], w2 = words[i + 1];
        int len = min(w1.length(), w2.length());
        bool found = false;
        
        for (int j = 0; j < len; ++j) {
            if (w1[j] != w2[j]) {
                graph[w1[j]].push_back(w2[j]);
                inDegree[w2[j]]++;
                found = true;
                break;
            }
        }

        if (!found && w1.length() > w2.length())
            return "";
    }

    queue<char> q;
    for (auto it = inDegree.begin(); it != inDegree.end(); ++it) {
        if (it->second == 0)
            q.push(it->first);
    }

    string result;
    while (!q.empty()) {
        char curr = q.front(); q.pop();
        result += curr;

        for (char neighbor : graph[curr]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0)
                q.push(neighbor);
        }
    }

    return result.length() == inDegree.size() ? result : "";
    }
};


//{ Driver Code Starts.

bool validate(const vector<string> &original, const string &order) {
    unordered_map<char, int> mp;
    for (const string &word : original) {
        for (const char &ch : word) {
            mp[ch] = 1;
        }
    }
    for (const char &ch : order) {
        if (mp.find(ch) == mp.end())
            return false;
        mp.erase(ch);
    }
    if (!mp.empty())
        return false;

    for (int i = 0; i < order.size(); i++) {
        mp[order[i]] = i;
    }

    for (int i = 0; i < original.size() - 1; i++) {
        const string &a = original[i];
        const string &b = original[i + 1];
        int k = 0, n = a.size(), m = b.size();
        while (k < n and k < m and a[k] == b[k]) {
            k++;
        }
        if (k < n and k < m and mp[a[k]] > mp[b[k]]) {
            return false;
        }
        if (k != n and k == m) {
            return false;
        }
    }
    return true;
}

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        string curr;
        vector<string> words;
        while (ss >> curr)
            words.push_back(curr);

        vector<string> original = words;

        Solution ob;
        string order = ob.findOrder(words);

        if (order.empty()) {
            cout << "\"\"" << endl;
        } else {
            cout << (validate(original, order) ? "true" : "false") << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends