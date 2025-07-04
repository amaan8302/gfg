class Solution {
  public:
    bool solve(vector<int>& arr, int k, int mid) 
    {
        int t = 0;
        for(int i : arr)
        {
            t+=i/mid;
            if(i%mid!=0)
                t++;
        }
        return t <= k;
    }
    int kokoEat(vector<int>& arr, int k) {
        int low = 1, high = *max_element(arr.begin(), arr.end());
        while(low < high) {
            int mid = low + (high - low) / 2;
            if(solve(arr, k, mid))
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }

};