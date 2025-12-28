class Solution {
  public:
    int kthSmallest(vector<vector<int>> &mat, int k) {
        int n = mat.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        for(int i = 0; i < n; i++)
            pq.push({mat[i][0], i, 0});
        int ans = 0;
        while(k--){
            auto v = pq.top();
            pq.pop();
            ans = v[0];
            int r = v[1];
            int c = v[2];

            if(c + 1 < n){
                pq.push({mat[r][c+1], r, c+1});
            }
        }
        return ans;
    }
};
