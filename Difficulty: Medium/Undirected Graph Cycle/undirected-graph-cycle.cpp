//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool dfs(int node, unordered_map<int, bool>& visited, unordered_map<int, list<int>>& adj, int parent) {
    visited[node] = true;
    for (auto &i : adj[node]) {
        if (i == parent)
            continue;
        if (visited[i])
            return true;
        if (dfs(i, visited, adj, node))
            return true;
    }
    return false;
}

bool isCycle(int V, vector<vector<int>>& edges) {
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    unordered_map<int, bool> visited;
    for (int i = 0; i < edges.size(); i++) {
        for (int j = 0; j < edges[i].size(); j++) {
            if (!visited[edges[i][j]] && dfs(edges[i][j], visited, adj, -1))
                return true;
        }
    }
    return false;
}

};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V, E;
        cin >> V >> E;
        cin.ignore();
        vector<vector<int>> edges;
        for (int i = 1; i <= E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        Solution obj;
        bool ans = obj.isCycle(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends