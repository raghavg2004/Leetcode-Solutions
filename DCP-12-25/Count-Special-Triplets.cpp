1class Solution {
2public:
3    int specialTriplets(vector<int>& nums) {
4        const int MOD = 1e9 + 7;
5        unordered_map<int, int> numCnt;
6        unordered_map<int, int> numPartialCnt;
7
8        numCnt.reserve(nums.size() * 2);
9        numPartialCnt.reserve(nums.size() * 2);
10
11        for (int v : nums) {
12            numCnt[v]++;
13        }
14
15        int ans = 0;
16        for (int v : nums) {
17            int target = v * 2;
18            int lCnt = numPartialCnt[target];
19            numPartialCnt[v]++;
20            int rCnt = numCnt[target] - numPartialCnt[target];
21            ans = (ans + (lCnt * 1LL * rCnt % MOD)) % MOD;
22        }
23
24        return ans;
25    }
26};