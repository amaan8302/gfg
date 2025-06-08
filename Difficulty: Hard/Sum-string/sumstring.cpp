class Solution {
  public:
    string addStrings(const string &a, const string &b) 
    {
        string res;
        int carry = 0, i = a.size()-1, j = b.size()-1;
    
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';
            res.push_back(sum % 10 + '0');
            carry = sum / 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
    
    bool isValid(const string &s) {
        return s.size() == 1 || s[0] != '0';
    }
    
    bool checkSumString(const string &s, int start, string num1, string num2) {
        if (!isValid(num1) || !isValid(num2)) return false;
    
        string sum = addStrings(num1, num2);
        int sumLen = sum.size();
    
        if (start + sumLen > s.size()) return false;
        if (s.substr(start, sumLen) != sum) return false;
        if (start + sumLen == s.size()) return true;
    
        return checkSumString(s, start + sumLen, num2, sum);
    }
    
    bool isSumString(string &s) {
        int n = s.size();
        for (int i = 1; i < n; ++i) {
            for (int j = 1; i + j < n; ++j) {
                string num1 = s.substr(0, i);
                string num2 = s.substr(i, j);
                if (checkSumString(s, i + j, num1, num2)) return true;
            }
        }
        return false;
    }

};