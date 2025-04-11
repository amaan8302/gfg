//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void finalans(vector<vector<char>>& board)
    {
        int n = board.size();
        int m = board[0].size();
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(board[i][j] == 'B')
                    board[i][j] = 'O';
                else if(board[i][j]=='O')
                    board[i][j] = 'X';
            }
        }
    }
    void dfs(vector<vector<char>>& board, int i , int j,int m ,int n)
    {
        if(i<0 || i>=m || j<0 || j>=n || board[i][j]!='O')
            return;
        board[i][j] = 'B';
        dfs(board,i+1,j,m,n);
        dfs(board,i-1,j,m,n);
        dfs(board,i,j+1,m,n);
        dfs(board,i,j-1,m,n);
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        for(int i = 0 ; i < n ; i++)
        {
            if(board[i][0]=='O')
                dfs(board , i , 0 , n , m);
            if(board[i][m-1]=='O')
                dfs(board , i , m-1, n ,m);
        }
        for(int i = 0 ; i < m ; i++)
        {
            if(board[0][i]=='O')
                dfs(board , 0 , i , n , m);
            if(board[n-1][i]=='O')
                dfs(board , n-1 , i , n ,m);
        }
        finalans(board);
    }
    vector<vector<char>> fill(vector<vector<char>>& mat) {
        solve(mat);
        return mat;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];

        Solution ob;
        vector<vector<char>> ans = ob.fill(mat);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends