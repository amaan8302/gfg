class Solution {
  public:
    int minCost(int n, int m, vector<int>& x, vector<int>& y) {
        sort(x.rbegin(), x.rend());
    sort(y.rbegin(), y.rend());

    int i = 0, j = 0;
    long long cost = 0;
    long long hParts = 1, vParts = 1;

    while (i < x.size() && j < y.size()) {
        if (x[i] > y[j]) {
            cost += 1LL * x[i] * hParts;
            vParts++;
            i++;
        } else {
            cost += 1LL * y[j] * vParts;
            hParts++;
            j++;
        }
    }
    while (i < x.size()) {
        cost += 1LL * x[i] * hParts;
        vParts++;
        i++;
    }
    while (j < y.size()) {
        cost += 1LL * y[j] * vParts;
        hParts++;
        j++;
    }
    return cost;
    }
};
