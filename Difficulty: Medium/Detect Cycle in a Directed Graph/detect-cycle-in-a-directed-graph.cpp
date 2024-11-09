//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isPresent(int node, unordered_map<int,bool>&visited,
        unordered_map<int,bool>&dfsOk,vector<vector<int>> &adj)
    {
        visited[node]=1;
        dfsOk[node]=1;
        for(auto i : adj[node])
        {
            if(!visited[i])
            {
                bool isCyclic = isPresent(i,visited,dfsOk,adj);
                if(isCyclic)
                    return 1;
            }
            else if(dfsOk[i])
                return 1;
        }
        dfsOk[node]=0;
        return 0;
    }
    bool isCyclic(int V, vector<vector<int>> adj) {
        // code here
        unordered_map<int,bool>visited;
        unordered_map<int,bool>dfsOk;
        for(int i = 0 ; i < V ; i++)
        {
            if(!visited[i])
            {
                if(isPresent(i,visited,dfsOk,adj))
                    return 1;
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends