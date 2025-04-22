class Solution {
public:
    const int MOD = 1e9 + 7;
    const int MAX = 10010;

    vector<long long> fact, inv_fact;

    long long modPow(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    void precomputeFactorials(int n) {
        fact.resize(n + 1);
        inv_fact.resize(n + 1);
        fact[0] = 1;
        for (int i = 1; i <= n; ++i)
            fact[i] = fact[i - 1] * i % MOD;

        inv_fact[n] = modPow(fact[n], MOD - 2);
        for (int i = n - 1; i >= 0; --i)
            inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
    }

    long long comb(int n, int r) {
        if (r > n) return 0;
        return fact[n] * inv_fact[r] % MOD * inv_fact[n - r] % MOD;
    }

    int idealArrays(int n, int maxValue) {
        precomputeFactorials(n + 100); // Safety margin for large exponent sums

        vector<int> dp(maxValue + 1, 1); // base case: length 1 for each number
        int ans = 0;

        for (int num = 1; num <= maxValue; ++num) {
            int temp = num;
            map<int, int> prime_exp;

            for (int i = 2; i * i <= temp; ++i) {
                while (temp % i == 0) {
                    prime_exp[i]++;
                    temp /= i;
                }
            }
            if (temp > 1) prime_exp[temp]++;

            long long ways = 1;
            for (auto& [prime, exp] : prime_exp) {
                ways = ways * comb(n - 1 + exp, exp) % MOD;
            }

            ans = (ans + ways) % MOD;
        }

        return ans;
    }
};
