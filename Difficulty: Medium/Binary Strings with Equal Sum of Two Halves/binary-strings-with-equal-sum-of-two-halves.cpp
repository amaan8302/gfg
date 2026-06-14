class Solution {
public:
    const int MOD = 1000000007;

    long long power(long long a, long long b) {
        long long ans = 1;

        while (b) {
            if (b & 1)
                ans = (ans * a) % MOD;

            a = (a * a) % MOD;
            b >>= 1;
        }

        return ans;
    }

    int computeValue(int n) {
        vector<long long> fact(2 * n + 1);

        fact[0] = 1;

        for (int i = 1; i <= 2 * n; i++)
            fact[i] = (fact[i - 1] * i) % MOD;

        long long den = (fact[n] * fact[n]) % MOD;

        return (fact[2 * n] * power(den, MOD - 2)) % MOD;
    }
};