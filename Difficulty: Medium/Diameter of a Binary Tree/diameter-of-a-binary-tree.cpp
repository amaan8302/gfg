class Solution {
  public:
    int solve(Node*root, int &res)
    {
        if(!root) return 0;
        int left = solve(root->left,res);
        int right = solve(root->right,res);
        res = max(res,left+right);
        return max(left,right)+1;
    }
    int diameter(Node* root) {
        int res = INT_MIN;
        solve(root,res);
        return res;
    }
};