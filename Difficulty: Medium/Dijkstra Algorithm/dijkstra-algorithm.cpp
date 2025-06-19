// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        unordered_map<int,list<pair<int,int>>>adj;
        for(int i = 0 ; i < edges.size() ;i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<int>distance(V,INT_MAX);
        distance[src]=0;
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>>pq;
        pq.push({0,src});
        while(!pq.empty()){
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto &i : adj[node])
            {
                int nd = i.first;
                int wt = i.second;
                if(wt+d < distance[nd])
                {
                    distance[nd] = wt+d;
                    pq.push({wt+d , nd});
                }
            }
        }
        return distance;
    }
};