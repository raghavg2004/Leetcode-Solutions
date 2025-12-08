1class Solution {
2public:
3    int countTriples(int n) {
4        int res = 0;
5        // enumerate a and b
6        for (int a = 1; a <= n; ++a) {
7            for (int b = 1; b <= n; ++b) {
8                // determine if it meets the requirements
9                int c = int(sqrt(a * a + b * b + 1.0));
10                if (c <= n && c * c == a * a + b * b) {
11                    ++res;
12                }
13            }
14        }
15        return res;
16    }
17};