class Solution {
  public:
    int findLength(vector<int> &color, vector<int> &radius) {
        stack<int>c,r;
        int n = color.size();
        c.push(-1);
        r.push(-1);
        for(int i = 0 ; i < n ; i++)
        {
            if(c.top()==color[i] && r.top()==radius[i])
            {
                c.pop();
                r.pop();
            }
            else
            {
                c.push(color[i]);
                r.push(radius[i]);   
            }
        }
        return c.size()-1;
    }
};