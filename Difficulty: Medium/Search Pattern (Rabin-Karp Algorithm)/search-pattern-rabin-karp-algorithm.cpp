class Solution {
  public:
    int p = 31;
    const int m = 1e9+7;
    vector<int> search(string &pat, string &txt) {
        int n = txt.size(), m_pat = pat.size();
        vector<long long> power(n + 1), h(n + 1);
        power[0] = 1;
        for (int i = 1; i <= n; i++)
            power[i] = (power[i - 1] * p) % m;
        for (int i = 0; i < n; i++)
            h[i + 1] = (h[i] + (txt[i] - 'a' + 1) * power[i]) % m;
        long long hs = 0;
        for (int i = 0; i < m_pat; i++)
            hs = (hs + (pat[i] - 'a' + 1) * power[i]) % m;
        vector<int> result;
        for (int i = 0; i + m_pat <= n; i++) {
            long long curH = (h[i + m_pat] - h[i] + m) % m;
            long long expected = (hs * power[i]) % m;
            if (curH == expected)
                result.push_back(i+1);
        }
        return result;
    }
};