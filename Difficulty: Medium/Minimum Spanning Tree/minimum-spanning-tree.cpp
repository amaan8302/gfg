//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	bool comparator(vector<int>&a, vector<int>&b)
    {
        return a[2] < b[2];
    }
    
    void makeSet(vector<int>& parent, vector<int>& rank, int n)
    {
        for(int i = 0; i < n; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }
    
    int FindParent(vector<int>& parent, int node)
    {
        if(parent[node] == node)
            return node;
        return parent[node] = FindParent(parent, parent[node]);
    }
    
    void unionSet(int u, int v, vector<int>& parent, vector<int>& rank)
    {
        u = FindParent(parent, u);
        v = FindParent(parent, v);
        if(rank[u] < rank[v])
            parent[u] = v;
        else if(rank[u] > rank[v])
            parent[v] = u;
        else
        {
            parent[v] = u;
            rank[u]++;
        }
    }

    int spanningTree(int V, vector<vector<int>> adj[])
{
    vector<vector<int>> edges;
    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            edges.push_back({i, it[0], it[1]});
        }
    }
    
    // Lambda function to compare edges based on weight
    auto comparator = [](vector<int>& a, vector<int>& b) {
        return a[2] < b[2];
    };

    sort(edges.begin(), edges.end(), comparator);
    
    vector<int> parent(V);
    vector<int> rank(V);
    makeSet(parent, rank, V);
    
    int MinWeight = 0;
    
    for (int i = 0; i < edges.size(); i++)
    {
        int u = FindParent(parent, edges[i][0]);
        int v = FindParent(parent, edges[i][1]);
        int wt = edges[i][2];
        
        if (u != v)
        {
            MinWeight += wt;
            unionSet(u, v, parent, rank);
        }
    }
    
    return MinWeight;
}

};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends