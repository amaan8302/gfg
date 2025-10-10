/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int solve(Node* root, int &maxSum) {
    if (root == NULL) return 0;
    int left = max(0, solve(root->left, maxSum));
    int right = max(0, solve(root->right, maxSum));
    int currentPathSum = root->data + left + right;
    maxSum = max(maxSum, currentPathSum);
    return root->data + max(left, right);
}

int findMaxSum(Node* root) {
    int maxSum = INT_MIN;
    solve(root, maxSum);
    return maxSum;
}
};