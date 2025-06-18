class Solution {
  public:
    int solve(Node* root,int &sum)
    {
        if(!root) return 0;
        int left = solve(root->left,sum);
        int right = solve(root->right,sum);
        sum = sum + root->data;
        return sum;
    }
    int sumBT(Node* root) {
        int sum = 0;
        solve(root,sum);
        return sum;
    }
};