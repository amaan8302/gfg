class Solution {
public:
    int bfsFarthest(int src, int n, vector<vector<int>>& adj, int& farthestNode) {
        vector<int> dist(n + 1, -1);
        queue<int> q;

        dist[src] = 0;
        q.push(src);

        int maxDist = 0;
        farthestNode = src;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            if (dist[u] > maxDist) {
                maxDist = dist[u];
                farthestNode = u;
            }

            for (int v : adj[u - 1]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        return maxDist;
    }
    int partyHouse(vector<vector<int>> &adj) {
        int n = adj.size();
        if (n <= 1) return 0;
        int u;
        bfsFarthest(1, n, adj, u);
        int v;
        int diameter = bfsFarthest(u, n, adj, v);
        return (diameter + 1) / 2;
    }
};