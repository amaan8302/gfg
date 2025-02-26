//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> distance(V, INT_MAX);
        set<pair<int, int>> setds;
        distance[S] = 0;
        setds.insert(make_pair(0, S));
        while (!setds.empty()) {
            auto top = *(setds.begin());
            int nodeDistance = top.first;
            int node = top.second;
            setds.erase(setds.begin());
            for (auto neighbor : adj[node]) {
                int adjNode = neighbor[0];
                int edgeWeight = neighbor[1];
    
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends