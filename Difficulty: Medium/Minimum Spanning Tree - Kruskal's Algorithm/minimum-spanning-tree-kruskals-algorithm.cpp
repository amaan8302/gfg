//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    bool comparator(vector<int>&a,vector<int>&b)
    {
      return a[2]<b[2];
    }
    void makeSet(vector<int>&parent,vector<int>&rank,int n)
    {
      for(int i=0;i<n;i++)
      {
        parent[i]=i;
        rank[i]=0;
      }
    }
    int FindParent(vector<int>&parent, int node)
    {
      if(parent[node]==node)
        return node;
      return FindParent(parent, parent[node]);
    }
    void unionSet(int u, int v, vector<int>&parent,vector<int>&rank)
    {
      u = FindParent(parent, u);
      v = FindParent(parent,v);
      if(rank[u]<rank[v])
        parent[u]=v;
      else if(rank[u]>rank[v]) 
        parent[v]=u;
      else
      {
        parent[v]=u;
        rank[u]++;
      }
    }
    int kruskalsMST(int n, vector<vector<int>> &edges) 
    {
        //   std::sort(edges.begin(), edges.end(), comparator);
        sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) 
        {
            return a[2] < b[2];
        });
          vector<int>parent(n);
          vector<int>rank(n);
          makeSet(parent,rank,n);
          int MinWeight=0;
          for(int i = 0 ; i < edges.size() ; i++)
          {
            int u = FindParent(parent,edges[i][0]);
            int v = FindParent(parent,edges[i][1]);
            int wt = edges[i][2];
            if(u!=v)
            {
              MinWeight+=wt;
              unionSet(u,v,parent,rank);
            }
          }
          return MinWeight;   
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
        }

        Solution obj;
        cout << obj.kruskalsMST(V, edges) << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends