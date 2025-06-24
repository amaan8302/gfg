class Solution {
  public:
    string maxSubseq(string& s, int k) {
        int n = s.size();
        int keep = n - k;
        string result;
        for (char c : s) {
            while (!result.empty() && k > 0 && result.back() < c) {
                result.pop_back();
                k--;
            }
            result.push_back(c);
        }
        result.resize(keep);
        return result;
    }
};
