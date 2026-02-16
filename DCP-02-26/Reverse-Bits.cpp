1class Solution {
2public:
3    uint32_t reverseBits(uint32_t n) {
4        uint32_t ans = 0;
5        for (int i = 0; i < 32 && n; ++i) {
6            ans |= (n & 1) << (31 - i);
7            n >>= 1;
8        }
9        return ans;
10    }
11};