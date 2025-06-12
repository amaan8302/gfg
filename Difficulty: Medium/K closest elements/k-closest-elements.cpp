class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int k, int x) {
        int n = arr.size();
    vector<int> res;
    
    // Find the index of the first element not less than x
    auto it = lower_bound(arr.begin(), arr.end(), x);
    int right = it - arr.begin();
    int left = right - 1;

    // Exclude x if it exists
    if (right < n && arr[right] == x) right++;

    while (k--) {
        if (left < 0) {
            res.push_back(arr[right++]);
        } else if (right >= n) {
            res.push_back(arr[left--]);
        } else {
            int distL = abs(arr[left] - x);
            int distR = abs(arr[right] - x);
            if (distL < distR || (distL == distR && arr[left] > arr[right])) {
                res.push_back(arr[left--]);
            } else {
                res.push_back(arr[right++]);
            }
        }
    }
    
    return res;
    }
};