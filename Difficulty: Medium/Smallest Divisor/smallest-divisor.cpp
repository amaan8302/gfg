class Solution {
  public:
    bool solve(int mid , int k , vector<int>&arr)
    {
        int t = 0;
        for(int i = 0 ; i < arr.size() ; i++)
        {
            if(arr[i]%mid==0)
                t+=arr[i]/mid;
            else
                t+=(arr[i]/mid)+1;
        }
        return t<=k;
    }
    int smallestDivisor(vector<int>& arr, int k) {
        int low = 1 , high = *max_element(begin(arr),end(arr)),ans=-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(solve(mid, k ,arr))
            {
                ans = mid;
                high = mid-1;
            }
            else
                low = mid + 1;
        }
        return ans;
    }
};
