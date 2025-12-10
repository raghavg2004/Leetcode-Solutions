1class Solution {
2public:
3    int countPermutations(vector<int>& complexity) {
4        int n = complexity.size();
5        if (*min_element(complexity.begin() + 1, complexity.end()) <=
6            complexity[0]) {
7            return 0;
8        }
9
10        int mod = 1000000007;
11        int ans = 1;
12        for (int i = 2; i < n; ++i) {
13            ans = static_cast<long long>(ans) * i % mod;
14        }
15        return ans;
16    }
17};