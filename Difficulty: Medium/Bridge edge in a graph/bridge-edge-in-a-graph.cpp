//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void dfs(int node, int parent, int &timer, vector<int>&discovery, vector<int>&low,
             vector<vector<int>>&result, unordered_map<int,list<int>>&adj, unordered_map<int,bool>&visited)
    {
        discovery[node] = low[node] = timer++;
        visited[node] = true;
        
        for (auto neighbor : adj[node]) {
            if (neighbor == parent)
                continue;
            if (!visited[neighbor]) {
                dfs(neighbor, node, timer, discovery, low, result, adj, visited);
                low[node] = min(low[node], low[neighbor]);
                if (low[neighbor] > discovery[node]) {
                    result.push_back({node, neighbor});
                }
            } else {
                low[node] = min(low[node], discovery[neighbor]);
            }
        }
    }
    vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
        unordered_map<int, list<int>> adj;
        for (auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> discovery(v, -1), low(v, -1);
        unordered_map<int, bool> visited;
        vector<vector<int>> result;
        int timer = 0;
        for (int i = 0; i < v; ++i) {
            if (!visited[i]) {
                dfs(i, -1, timer, discovery, low, result, adj, visited);
            }
        }
        return result;
    }
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        vector<vector<int>> bridges = findBridges(edges, V, edges.size());
        for (auto &bridge : bridges) 
        {
            if ((bridge[0] == c && bridge[1] == d) || (bridge[0] == d && bridge[1] == c))
                return true;
        }
        return false;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        vector<vector<int>> edges(E);
        int i = 0;
        while (i++ < E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            edges[i - 1].push_back(u);
            edges[i - 1].push_back(v);
        }

        int c, d;
        cin >> c >> d;

        Solution obj;
        bool l = obj.isBridge(V, edges, c, d);
        if (l)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends