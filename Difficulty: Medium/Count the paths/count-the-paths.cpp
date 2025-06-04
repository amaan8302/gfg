class Solution {
  public:
    int countPaths(vector<vector<int>>& edges, int V, int src, int dest) {
        vector<vector<int>> adj(V);
        vector<int> indegree(V, 0);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }

        // Topological Sort (Kahn's Algorithm)
        queue<int> q;
        for (int i = 0; i < V; ++i)
            if (indegree[i] == 0)
                q.push(i);

        vector<int> topo;
        while (!q.empty()) {
            int node = q.front(); q.pop();
            topo.push_back(node);
            for (int nei : adj[node]) {
                if (--indegree[nei] == 0)
                    q.push(nei);
            }
        }

        // DP to count paths
        vector<long long> dp(V, 0);
        dp[src] = 1;

        for (int u : topo) {
            for (int v : adj[u]) {
                dp[v] += dp[u];
            }
        }
        return dp[dest];
    }
};