class Solution {
  public:
    int countValid(int n, vector<int>& arr) {
        unordered_set<int> forbidden(arr.begin(), arr.end());
        vector<int> allowed;
        for (int d = 0; d <= 9; ++d) {
            if (forbidden.find(d) == forbidden.end())
                allowed.push_back(d);
        }
        if (allowed.empty()) return 0;
        int total = 9 * pow(10, n - 1);
        int count = 0;
        for (int d : allowed) {
            if (d == 0) continue;
            int ways = 1;
            for (int i = 1; i < n; ++i) {
                ways *= allowed.size();
            }
            count += ways;
        }
        return total - count;
    }
};
