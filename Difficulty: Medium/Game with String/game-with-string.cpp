class Solution {
  public:
    int minValue(string &s, int k) 
    {
        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;
        
        priority_queue<int> pq;
        for (auto &ch : freq) pq.push(ch.second);
        
        while (k-- && !pq.empty()) {
            int top = pq.top(); pq.pop();
            if (--top > 0) pq.push(top);
        }
        
        int result = 0;
        while (!pq.empty()) {
            int f = pq.top(); pq.pop();
            result += f * f;
        }
        return result;
    }
};