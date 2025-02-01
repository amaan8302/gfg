//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int n, m, l;
bool valid(int i, int j, int idx, vector<vector<char>>& mat, vector<vector<bool>>& visited, string& word) {
    if (idx == l) return true;
    if (i < 0 || i >= n || j < 0 || j >= m || visited[i][j] || mat[i][j] != word[idx]) return false;

    visited[i][j] = true;
    bool found = valid(i - 1, j, idx + 1, mat, visited, word) ||
                 valid(i, j - 1, idx + 1, mat, visited, word) ||
                 valid(i, j + 1, idx + 1, mat, visited, word) ||
                 valid(i + 1, j, idx + 1, mat, visited, word);
    visited[i][j] = false;

    return found;
}

bool isWordExist(vector<vector<char>>& mat, string& word) {
    n = mat.size();
    m = mat[0].size();
    l = word.size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == word[0]) {
                vector<vector<bool>> visited(n, vector<bool>(m, false));
                if (valid(i, j, 0, mat, visited, word)) return true;
            }
        }
    }
    return false;
}

};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m, '*'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        string word;
        cin >> word;
        Solution obj;
        bool ans = obj.isWordExist(mat, word);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends

