//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int k)  {
        unordered_map<int,list<pair<int,int>>>adj;
        for(int i = 0 ; i < flights.size();i++)
        {
            int u = flights[i][0];
            int v = flights[i][1];
            int w = flights[i][2];
            adj[u].push_back({v,w});
        }
        int stops = 0;
        vector<int>cost(n,INT_MAX);
        queue<pair<int,int>>que;
        que.push({src,0});
        cost[src]=0;
        while(!que.empty() && stops<=k)
        {
            int size = que.size();
            while(size--)
            {
                pair<int,int>top = que.front();
                int u = top.first;
                int d = top.second;
                que.pop();
                for(pair<int,int>&i:adj[u])
                {
                    int v = i.first;
                    int cst = i.second;
                    if(cost[v]>d+cst)
                    {
                        cost[v] = d+cst;
                        que.push({v,d+cst});
                    }
                }    
            }
            stops++;
        }
        if(cost[dst]==INT_MAX)
            return -1;
        return cost[dst];
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends