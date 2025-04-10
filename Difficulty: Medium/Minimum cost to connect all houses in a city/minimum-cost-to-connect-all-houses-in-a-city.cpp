//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    typedef pair<int, int> p;
    int solve(int V, vector<vector<p>>&adj)
    {
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
                int adjNode = adj[node][i].first;
                int weight = adj[node][i].second;
                if (!isMST[adjNode]) {
                    pq.push({weight, adjNode});
                }
            }
        }
        return sum;
    }
    int minCost(vector<vector<int>>& points) {
        int V = points.size();
        vector<vector<p>>adj(V);
        for(int i = 0 ; i < V ; i++) {
            for(int j = i+1 ; j < V ; j++) {
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                int dis = abs(x1 - x2) + abs(y1 - y2);
                adj[i].push_back({j, dis});
                adj[j].push_back({i, dis});
            }
        }
        return solve(V, adj);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> edges;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;

        cout << obj.minCost(edges);
        cout << "\n";
        cout << "~" << endl;
    }
}

// } Driver Code Ends