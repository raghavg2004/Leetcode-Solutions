1class Solution {
2public:
3    int longestBalanced(vector<int>& nums) {
4        size_t len = 0;
5
6        for (size_t i = 0; i < nums.size(); i++) {
7            auto odd = unordered_map<int, int>();
8            auto even = unordered_map<int, int>();
9
10            for (size_t j = i; j < nums.size(); j++) {
11                auto& c = (nums[j] & 1) ? odd : even;
12                c[nums[j]]++;
13
14                if (odd.size() == even.size()) {
15                    len = std::max(len, j - i + 1);
16                }
17            }
18        }
19
20        return int(len);
21    }
22};