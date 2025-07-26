class Solution {
  public:
    vector<int> findMajority(vector<int>& arr) {
        // Code here
        unordered_map<int,int>mp;
        for(int i : arr)
            mp[i]++;
        int n = arr.size()/3;
        vector<int>ans;
        for(auto &i : mp)
        {
            if(i.second > n) ans.push_back(i.first);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};