1class Solution {
2public:
3    int minRemoval(vector<int>& nums, int k) {
4        int n = nums.size();
5        sort(nums.begin(), nums.end());
6
7        int ans = n, right = 0;
8        for (int left = 0; left < n; ++left) {
9            while (right < n &&
10                   nums[right] <= static_cast<long long>(nums[left]) * k) {
11                ++right;
12            }
13            ans = min(ans, n - (right - left));
14        }
15
16        return ans;
17    }
18};