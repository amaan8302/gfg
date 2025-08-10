class Solution {
  public:
    int countPS(string &s) 
    {
        int n = s.size();
        int count = 0;
        for (int center = 0; center < n; center++) {
            int l = center, r = center + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                count++;
                l--;
                r++;
            }
            l = center - 1;
            r = center + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 >= 2) count++;
                l--;
                r++;
            }
        }
        return count;
    }
};