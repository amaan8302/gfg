class Solution {
  public:
    int minSoldiers(vector<int>& arr, int k) {
        int n = arr.size();
        int target = (n+1)/2;
        vector<int> extraSolNeeded;
        int cnt = 0;
        for(int i : arr)
        {
            if(i%k==0)
                cnt++;
            else
                extraSolNeeded.push_back(k- (i%k));
        }
        if(cnt>=target)
            return 0;
        int res = 0;
        std::sort(extraSolNeeded.begin(),extraSolNeeded.end());
        for(int i : extraSolNeeded)
        {
            res+=i;
            cnt++;
            if(cnt>=target)
                break;
        }
        return res;
    }
};