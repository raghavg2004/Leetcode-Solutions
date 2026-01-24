1class Solution {
2public:
3    int minPairSum(vector<int>& nums) {
4        sort(nums.begin(), nums.end());
5        
6        int maxSum = 0;
7        for (int i = 0; i < nums.size() / 2; i++) {
8            maxSum = max(maxSum, nums[i] + nums[nums.size() - 1 - i]);
9        }
10        
11        return maxSum;
12    }
13};