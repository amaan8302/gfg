//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(int node, vector<bool>& visited, vector<vector<int>>& isConnected) 
    {
        visited[node] = true;
        for (int i = 0; i < isConnected.size(); ++i) {
            if (isConnected[node][i] == 1 && !visited[i]) {
                dfs(i, visited, isConnected);
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int n) {
        // code here
        vector<bool> visited(n, false);
        int cnt = 0;
        
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                cnt++;
                dfs(i, visited, adj);
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends