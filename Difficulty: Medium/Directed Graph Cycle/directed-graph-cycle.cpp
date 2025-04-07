//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool dfs(int node, unordered_map<int,list<int>>&adj, 
    unordered_map<int,bool>&vis,unordered_map<int,bool>&currVis)
    {
        vis[node]=1;
        currVis[node]=1;
        for(auto &i:adj[node])
        {
            if(!vis[i])
            {
                if(dfs(i,adj,vis,currVis))
                return 1;
            }
            if(currVis[i])
                return 1;
        }
        currVis[node]=0;
        return 0;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        unordered_map<int,list<int>>adj;
        unordered_map<int,bool>vis;
        for(int i = 0 ; i < edges.size() ; i++)
        {
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
        }
        for(int i = 0 ; i < V ; i++)
        {
            unordered_map<int,bool>currVis;
            if(dfs(i,adj,vis,currVis))
                return 1;
        }
        return 0;
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
        bool ans = obj.isCyclic(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";
    }
    return 0;
}
// } Driver Code Ends