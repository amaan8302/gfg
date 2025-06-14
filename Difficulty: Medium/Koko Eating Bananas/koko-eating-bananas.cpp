class Solution {
  public:
    bool solve(vector<int>& arr, int k, int mid) 
    {
        int t = 0;
        for(int i = 0; i < arr.size(); i++) 
            t += (arr[i] + mid - 1) / mid;
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