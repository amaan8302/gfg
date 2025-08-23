class Solution {
  public:
    bool isPossible(vector<int>& arr, int k, int mid) 
    {
        int students = 1, pages = 0;
        for (int pagesInBook : arr) {
            if (pages + pagesInBook > mid) {
                students++;
                pages = pagesInBook;
                if (students > k) return false;
            } else {
                pages += pagesInBook;
            }
        }
        return true;
    }

    int findPages(vector<int> &arr, int k) 
    {
        int n = arr.size();
        if (k > n) return -1;
    
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        int ans = -1;
    
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(arr, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};