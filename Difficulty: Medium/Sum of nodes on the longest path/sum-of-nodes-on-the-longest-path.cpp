class Solution {
  public:
    void solve(Node *root , int &maxLen, int &maxSum, int sum, int len)
    {
        if(!root){
            if(len>maxLen){
                maxLen = len;
                maxSum = sum;
            }
            else if(len==maxLen)
                maxSum = max(sum, maxSum);
            return;
        }
        sum = sum + root->data;
        solve(root->left, maxLen, maxSum, sum, len+1);
        solve(root->right, maxLen, maxSum, sum, len+1);
    }
    int sumOfLongRootToLeafPath(Node *root) {
        int len = 0, maxLen = 0, sum = 0, maxSum = INT_MIN;
        solve(root,maxLen,maxSum,sum,len);
        return maxSum;
    }
};