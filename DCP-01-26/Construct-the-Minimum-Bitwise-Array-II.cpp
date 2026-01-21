1class Solution {
2public:
3    vector<int> minBitwiseArray(vector<int>& nums) {
4        for (int& x : nums) {
5            int res = -1;
6            int d = 1;
7            while ((x & d) != 0) {
8                res = x - d;
9                d <<= 1;
10            }
11            x = res;
12        }
13        return nums;
14    }
15};