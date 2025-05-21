class Solution {
  public:
    int countLessEqual(int m, int n, int x) 
    {
        int count = 0;
        for (int i = 1; i <= m; i++) {
            count += min(x / i, n);
        }
        return count;
    }
    
    int kthSmallest(int m, int n, int k) {
        int low = 1, high = m * n;
        while (low < high) {
            int mid = (low + high) / 2;
            if (countLessEqual(m, n, mid) < k)
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }
};
