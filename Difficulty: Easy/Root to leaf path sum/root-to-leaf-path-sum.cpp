class Solution {
  public:
    bool solve(Node* root, int sum,int target)
    {
        if(!root) return 0;
        sum = sum + root->data;
        if(!root->left && !root->right && sum==target)
            return 1;
        bool left = solve(root->left,sum,target);
        bool right = solve(root->right,sum,target);
        return left||right;
    }
    bool hasPathSum(Node *root, int target) {
        return solve(root,0,target);
    }
};