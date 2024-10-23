//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>>& mat) {
        // Code here
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>>result(m,vector<int>(n,-1));
        vector<vector<int>>direc{{0,1},{0,-1},{1,0},{-1,0}};
        queue<pair<int,int>>que;
        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(mat[i][j]==1)
                {
                    result[i][j] = 0;
                    que.push({i,j});
                }
            }
        }
        while(!que.empty())
        {
            pair<int,int>p = que.front();
            que.pop();
            int i = p.first;
            int j = p.second;
            for(auto &x :direc)
            {
                int ni = i + x[0];
                int nj = j + x[1];
                if(ni>=0 && ni < m && nj >= 0 && nj < n && result[ni][nj]==-1)
                {
                    result[ni][nj] = result[i][j]+1;
                    que.push({ni,nj});
                }
            }
        }
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        vector<vector<int>> ans = obj.nearest(grid);
        for (auto i : ans) {
            for (auto j : i) {
                cout << j << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends