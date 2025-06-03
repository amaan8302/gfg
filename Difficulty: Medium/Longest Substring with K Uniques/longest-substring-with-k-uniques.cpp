// User function template for C++

class Solution {
  public:
    int longestKSubstr(string &s, int k)
    {
        int i = 0, j = 0, maxi = -1, count = 0;
        vector<int> vec(26, 0);
    
        while (j < s.length()) {
            if (vec[s[j] - 'a'] == 0)
                count++;
            vec[s[j] - 'a']++;
    
            while (count > k) {
                vec[s[i] - 'a']--;
                if (vec[s[i] - 'a'] == 0)
                    count--;
                i++;
            }
    
            if (count == k)
                maxi = max(maxi, j - i + 1);
    
            j++;
        }
    
       return maxi;
    }
};