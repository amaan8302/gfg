//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isBipartite(int V, vector<int> adj[]) {
    vector<int> v(V, -1);
    for (int i = 0; i < V; ++i) {
        if (v[i] == -1) {
            queue<int> q;
            q.push(i);
            v[i] = 0;
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                for (int n : adj[node]) {
                    if (v[n] == -1) {
                        v[n] = 1 - v[node];
                        q.push(n);
                    } else if (v[n] == v[node]) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}


};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends