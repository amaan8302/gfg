class Solution {
  public:
    int atMostK(string& s, int k) 
    {
        int n = s.size(), left = 0, right = 0, count = 0;
        unordered_map<char, int> freq;
        while (right < n) {
            freq[s[right]]++;
            while (freq.size() > k) {
                freq[s[left]]--;
                if (freq[s[left]] == 0)
                    freq.erase(s[left]);
                left++;
            }
            count += (right - left + 1);
            right++;
        }
        return count;
    }
    int countSubstr(string& s, int k) {
        return atMostK(s, k) - atMostK(s, k - 1);
    }
};