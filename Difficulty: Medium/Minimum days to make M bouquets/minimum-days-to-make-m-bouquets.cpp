class Solution {
  public:
    bool isPossible(vector<int>&arr, int day, int m, int k)
    {
        int cnt = 0, bouquet = 0;
        for(int i = 0 ; i < arr.size() ; i++)
        {
            if(arr[i]<=day)
                cnt++;
            else
            {
                bouquet+=cnt/k;
                cnt = 0;
            }
        }
        bouquet += cnt / k; 
        return bouquet>=m;
    }
    int minDaysBloom(vector<int>& arr, int k, int m)
    {
        int low = 0;
        int high = *max_element(begin(arr),end(arr));
        int ans = -1;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(isPossible(arr,mid,m,k))
            {
                high = mid - 1;
                ans = mid;
            }
            else 
                low = mid + 1;
        }
        return ans;
    }
};