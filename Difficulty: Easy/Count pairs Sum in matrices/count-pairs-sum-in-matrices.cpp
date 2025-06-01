class Solution {
  public:
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int x) {
        unordered_map<int,bool>mp;
        int n = mat1.size();
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < n ; j++)
                mp[mat2[i][j]]=true;
        }
        int cnt=0;
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(mp[x-mat1[i][j]])
                    cnt++;
            }
        }
        return cnt;
    }
};