class Solution {
  public:
    int balanceSums(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<int> rowSum(n, 0), colSum(n, 0);
        int totalSum = 0, maxSum = 0;
    
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) {
                rowSum[i] += mat[i][j];
                colSum[j] += mat[i][j];
                totalSum += mat[i][j];
            }
    
        for (int i = 0; i < n; ++i)
            maxSum = max({maxSum, rowSum[i], colSum[i]});
    
        return n * maxSum - totalSum;
    }
};