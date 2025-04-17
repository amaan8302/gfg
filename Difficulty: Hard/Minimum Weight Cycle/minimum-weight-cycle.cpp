//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findMinCycle(int V, vector<vector<int>>& edges) {
        int min_cycle = INT_MAX;
    
    // Build adjacency list
    vector<vector<pair<int, int>>> adj(V);
    for (const auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    
    for (const auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        
        // Temporarily remove the edge u-v
        // To do this, we can exclude this edge during Dijkstra's traversal
        
        // Priority queue for Dijkstra's: (distance, node)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(V, INT_MAX);
        dist[u] = 0;
        pq.push({0, u});
        
        while (!pq.empty()) {
            int current_dist = pq.top().first;
            int current_node = pq.top().second;
            pq.pop();
            
            if (current_dist > dist[current_node]) {
                continue;
            }
            
            for (const auto& neighbor_pair : adj[current_node]) {
                int neighbor = neighbor_pair.first;
                int weight = neighbor_pair.second;
                
                // Skip the edge between u and v to simulate its removal
                if ((current_node == u && neighbor == v) || (current_node == v && neighbor == u)) {
                    continue;
                }
                
                if (dist[neighbor] > current_dist + weight) {
                    dist[neighbor] = current_dist + weight;
                    pq.push({dist[neighbor], neighbor});
                }
            }
        }
        
        if (dist[v] != INT_MAX) {
            min_cycle = min(min_cycle, dist[v] + w);
        }
    }
    
    return min_cycle == INT_MAX ? -1 : min_cycle;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> edges;
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back({u, v, w});
            edges.push_back({v, u, w});
        }

        Solution obj;
        int res = obj.findMinCycle(V, edges);

        cout << res << endl;
    }

    return 0;
}
// } Driver Code Ends