//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    typedef pair<int, int> p;
    int spanningTree(int V, vector<vector<int>> adj[]) {
        priority_queue<p, vector<p>, greater<p>> pq;
        pq.push({0, 0});
        vector<bool> isMST(V, false);
        int sum = 0;
    
        while (!pq.empty()) {
            p top = pq.top();
            pq.pop();
            int wt = top.first;
            int node = top.second;
    
            if (isMST[node]) continue;
            isMST[node] = true;
            sum += wt;
    
            for (int i = 0; i < adj[node].size(); ++i) {
                int adjNode = adj[node][i][0];
                int weight = adj[node][i][1];
                if (!isMST[adjNode]) {
                    pq.push({weight, adjNode});
                }
            }
        }
    
        return sum;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends