1class Solution {
2public:
3    long long maximumProfit(vector<int>& prices, int k) {
4        int n = prices.size();
5        vector<vector<vector<long long>>> memo(
6            n, vector<vector<long long>>(k + 1, vector<long long>(3, -1)));
7
8        function<long long(int, int, int)> dfs = [&](int i, int j,
9                                                     int state) -> long long {
10            if (j == 0) {
11                return 0;
12            }
13            if (i == 0) {
14                return state == 0 ? 0 : (state == 1 ? -prices[0] : prices[0]);
15            }
16            if (memo[i][j][state] != -1) {
17                return memo[i][j][state];
18            }
19
20            int p = prices[i];
21            long long res;
22            if (state == 0) {
23                res = max(dfs(i - 1, j, 0),
24                          max(dfs(i - 1, j, 1) + p, dfs(i - 1, j, 2) - p));
25            } else if (state == 1) {
26                res = max(dfs(i - 1, j, 1), dfs(i - 1, j - 1, 0) - p);
27            } else {
28                res = max(dfs(i - 1, j, 2), dfs(i - 1, j - 1, 0) + p);
29            }
30            memo[i][j][state] = res;
31
32            return res;
33        };
34
35        return dfs(n - 1, k, 0);
36    }
37};