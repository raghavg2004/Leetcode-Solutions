1class Solution {
2    public int countBinarySubstrings(String s) {
3        int ans = 0, prev = 0, cur = 1;
4        for (int i = 1; i < s.length(); i++) {
5            if (s.charAt(i-1) != s.charAt(i)) {
6                ans += Math.min(prev, cur);
7                prev = cur;
8                cur = 1;
9            } else {
10                cur++;
11            }
12        }
13        return ans + Math.min(prev, cur);
14    }
15}