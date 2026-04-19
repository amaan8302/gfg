class Solution {
  public:
    bool isPower(int x, int y) {
        if (x == 1) return y == 1;
        double val = log(y) / log(x);
        return abs(val - round(val)) < 1e-10;
    }
};