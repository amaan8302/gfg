class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        int n = arr.size();
        for(int i = 0 ; i < n ; i++)
        {
            int x = arr[i];
            arr[i] = pow(x,2);
        }
        unordered_map<int,bool>mp;
        for(int i : arr)
            mp[i]=1;
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = i+1 ; j < n ; j++)
            {
                if(mp[arr[i]+arr[j]])
                    return true;
            }
        }
        return false;
    }
};