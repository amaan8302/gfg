//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    bool isSafe(int newx, int newy, vector<vector<bool>>& visited, vector<vector<int>>& arr, int n) 
    {
        return newx >= 0 && newx < n && newy >= 0 && newy < n && !visited[newx][newy] && arr[newx][newy] == 1;
    }
    void solve(int x, int y, vector<vector<int>>& arr, int n, vector<string>& ans, vector<vector<bool>>& visited, string path) 
    {
        if (x == n - 1 && y == n - 1) 
        {
            ans.push_back(path);
            return;
        }
        visited[x][y] = 1;
        if (isSafe(x + 1, y, visited, arr, n))
            solve(x + 1, y, arr, n, ans, visited, path + 'D');
        if (isSafe(x, y - 1, visited, arr, n))
            solve(x, y - 1, arr, n, ans, visited, path + 'L');
        if (isSafe(x, y + 1, visited, arr, n))
            solve(x, y + 1, arr, n, ans, visited, path + 'R');
        if (isSafe(x - 1, y, visited, arr, n))
            solve(x - 1, y, arr, n, ans, visited, path + 'U');
        visited[x][y] = 0;
    }
    vector<string> findPath(vector<vector<int>> &arr) {
        int n = arr.size();
        vector<string> ans;
        vector<vector<bool>> visited(n, vector<bool>(n, 0));
        string path = "";
        if (arr[0][0] == 0) 
            return ans;
        solve(0, 0, arr, n, ans, visited, path);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        vector<vector<int>> mat;
        string innerArray;
        bool isInsideArray = false;

        for (char c : input) {
            if (c == '[') {
                if (isInsideArray) {
                    innerArray.clear();
                }
                isInsideArray = true;
            } else if (c == ']') {
                if (isInsideArray && !innerArray.empty()) {
                    vector<int> row;
                    stringstream ss(innerArray);
                    int num;

                    while (ss >> num) {
                        row.push_back(num);
                        if (ss.peek() == ',')
                            ss.ignore();
                        while (isspace(ss.peek()))
                            ss.ignore();
                    }

                    mat.push_back(row);
                    innerArray.clear();
                }
                isInsideArray = false;
            } else if (isInsideArray) {
                if (!isspace(c)) {
                    innerArray += c;
                }
            }
        }

        Solution obj;
        vector<string> result = obj.findPath(mat);
        sort(result.begin(), result.end());

        if (result.empty())
            cout << "[]";
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends