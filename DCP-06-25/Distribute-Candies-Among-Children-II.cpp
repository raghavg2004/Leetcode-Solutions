#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll comb(ll n) {
    if (n < 0) return 0;
    return (n * (n - 1)) / 2;
}

class Solution {
public:
    long long distributeCandies(int n, int limit) {
        ll total = 0;
        for (int mask = 0; mask < 8; ++mask) {
            int bits = __builtin_popcount(mask);
            ll subtract = (limit + 1LL) * bits;
            ll rem = n - subtract;
            ll ways = comb(rem + 2);
            if (bits % 2 == 0) total += ways;
            else total -= ways;
        }
        return total;
    }
};
