class Solution {
  public:
    void dfs(Node* root, int hd, map<int, long long>& mp) {
        if (!root) return;

        mp[hd] += root->data;

        dfs(root->left, hd - 1, mp);
        dfs(root->right, hd + 1, mp);
    }
    vector<int> verticalSum(Node* root) {
        map<int, long long> mp;
        dfs(root, 0, mp);

        vector<int> ans;
        for (auto &it : mp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};