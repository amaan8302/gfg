class Solution {
  public:
    vector<int> leafNodes(vector<int>& preorder) {
        vector<int> leaves;
        stack<int> st;
        for (int i = 0; i < preorder.size() - 1; ++i) 
        {
            int current = preorder[i];
            int next = preorder[i + 1];
            bool isLeaf = false;
            if (next < current)
                st.push(current);
            else 
            {
                while (!st.empty() && next > st.top()) 
                {
                    st.pop();
                    isLeaf = true;
                }
                if (isLeaf)
                    leaves.push_back(current);
            }
        }
        leaves.push_back(preorder.back());
        return leaves;
    }
};