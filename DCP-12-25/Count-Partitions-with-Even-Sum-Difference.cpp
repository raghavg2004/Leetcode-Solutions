1class Solution {
2public:
3    int countPartitions(vector<int>& nums) {
4        int totalSum = 0;
5        for (int x : nums) {
6            totalSum += x;
7        }
8        return totalSum % 2 == 0 ? nums.size() - 1 : 0;
9    }
10};