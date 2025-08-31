class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n=arr.size(),i = 0, j = n-1,area = INT_MIN;
        if(n==1)
            return 0;
        while(i<j)
        {
            area = max(area , (j-i)*min(arr[i],arr[j]));
            if(arr[j]>arr[i])
                i++;
            else
                j--;
        }
        return area;
    }
};