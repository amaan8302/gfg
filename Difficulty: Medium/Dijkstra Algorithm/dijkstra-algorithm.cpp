//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User Function Template
class Solution {
  public:
    typedef pair<int, int> p;
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int S) {
        unordered_map<int,list<pair<int,int>>>adj;
        for(int i = 0 ; i < edges.size() ; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<int> distance(V, INT_MAX);
        set<p>setds;
        distance[S] = 0;
        setds.insert({0, S});
        while (!setds.empty()) {
            p top = *(setds.begin());
            int nodeDistance = top.first;
            int node = top.second;
            setds.erase(setds.begin());
            for (auto neighbor : adj[node]) {
                int adjNode = neighbor.first;
                int edgeWeight = neighbor.second;
                if (nodeDistance + edgeWeight < distance[adjNode]) {
                    auto it = setds.find(make_pair(distance[adjNode], adjNode));
                    if (it != setds.end())
                        setds.erase(it);
                    distance[adjNode] = nodeDistance + edgeWeight;
                    setds.insert(make_pair(distance[adjNode], adjNode));
                }
            }
        }
        return distance;
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
        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.dijkstra(V, edges, src);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends