1class Solution {
2    public boolean hasAlternatingBits(int n) {
3        int cur = n % 2;
4        n /= 2;
5        while (n > 0) {
6            if (cur == n % 2) return false;
7            cur = n % 2;
8            n /= 2;
9        }
10        return true;
11    }
12}