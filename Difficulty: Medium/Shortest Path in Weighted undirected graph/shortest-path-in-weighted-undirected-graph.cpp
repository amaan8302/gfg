//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
    vector<vector<pair<int, int>>> adj(n + 1);
    for (auto &edge : edges) {
        int u = edge[0], v = edge[1], w = edge[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    vector<int> dist(n + 1, INT_MAX), parent(n + 1, -1);
    set<pair<int, int>> s;
    dist[1] = 0;
    s.insert({0, 1});

    while (!s.empty()) {
        auto top = *s.begin();
        int d = top.first, u = top.second;
        s.erase(s.begin());

        for (auto &i : adj[u]) {
            int v = i.first, w = i.second; // Fix: correctly extract v and w
            if (dist[u] + w < dist[v]) {
                s.erase({dist[v], v});
                dist[v] = dist[u] + w;
                parent[v] = u;
                s.insert({dist[v], v});
            }
        }
    }

    if (dist[n] == INT_MAX) return {-1}; 

    vector<int> path;
    for (int node = n; node != -1; node = parent[node])
        path.push_back(node);
    
    reverse(path.begin(), path.end());
    path.insert(path.begin(), dist[n]);

    return path;
}

};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
            mp[{edges.back()[0], edges.back()[1]}] = edges.back()[2];
            mp[{edges.back()[1], edges.back()[0]}] = edges.back()[2];
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        int ans = 0;
        for (int i = 2; i < res.size(); i++) {
            ans += mp[{res[i], res[i - 1]}];
        }
        if (ans == res[0]) {

        } else if (res.size() == 1 && res[0] == -1)
            ans = res[0];
        else
            ans = -2;
        cout << ans << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends