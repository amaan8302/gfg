//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        int cntFresh = 0;
        int vis[n][m];
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                } else {
                    vis[i][j] = 0;
                }
                if(grid[i][j] == 1) cntFresh++;
            }
        }        
        int time = 0;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        int rotted = 0;     
        while(!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            time = max(time, t);
            q.pop();
            
            for(int i = 0; i < 4; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1) 
                {
                    q.push({{nrow, ncol}, t + 1});
                    vis[nrow][ncol] = 2;
                    rotted++;
                }
            }
        }    
        if(rotted != cntFresh) return -1;
        return time;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends