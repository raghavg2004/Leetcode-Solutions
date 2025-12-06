1class Solution {
2public:
3    int countPartitions(vector<int>& nums, int k) {
4        int n = nums.size();
5        long long mod = 1e9 + 7;
6        vector<long long> dp(n + 1);
7        vector<long long> prefix(n + 1);
8        multiset<int> cnt;
9        dp[0] = 1;
10        prefix[0] = 1;
11        for (int i = 0, j = 0; i < nums.size(); i++) {
12            cnt.emplace(nums[i]);
13            // adjust window
14            while (j <= i && *cnt.rbegin() - *cnt.begin() > k) {
15                cnt.erase(cnt.find(nums[j]));
16                j++;
17            }
18            dp[i + 1] = (prefix[i] - (j > 0 ? prefix[j - 1] : 0) + mod) % mod;
19            prefix[i + 1] = (prefix[i] + dp[i + 1]) % mod;
20        }
21        return dp[n];
22    }
23};