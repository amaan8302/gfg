class Solution {
  public:
int min_operations(vector<int>& nums) {
    int n = nums.size();
    
    vector<int> transformed(n);
    for (int i = 0; i < n; i++) {
        transformed[i] = nums[i] - i;
    }
    
    vector<int> tails;
    
    for (int x : transformed) {
        auto it = upper_bound(tails.begin(), tails.end(), x);
        if (it == tails.end()) {
            tails.push_back(x);
        } else {
            *it = x;
        }
    }
    
    return n - (int)tails.size();
    }
};