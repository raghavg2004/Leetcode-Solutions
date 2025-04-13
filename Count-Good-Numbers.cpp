class Solution {
public:
    const int MOD = 1e9 + 7;

    // Fast modular exponentiation
    long long modPow(long long base, long long exp, long long mod) {
        long long result = 1;
        base %= mod;

        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long even_count = (n + 1) / 2; // positions: 0,2,4,...
        long long odd_count = n / 2;        // positions: 1,3,5,...

        long long evenWays = modPow(5, even_count, MOD);
        long long oddWays = modPow(4, odd_count, MOD);

        return (int)((evenWays * oddWays) % MOD);
    }
};
