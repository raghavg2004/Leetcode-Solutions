1class Solution {
2public:
3    int maxProfit(int n, vector<int>& present, vector<int>& future,
4                  vector<vector<int>>& hierarchy, int budget) {
5        vector<vector<int>> g(n);
6
7        for (auto& e : hierarchy) {
8            g[e[0] - 1].push_back(e[1] - 1);
9        }
10
11        auto dfs = [&](auto&& self,
12                       int u) -> tuple<vector<int>, vector<int>, int> {
13            int cost = present[u];
14            int dCost = present[u] / 2;  // discounted cost
15
16            // dp[u][state][budget]
17            // state = 0: Do not purchase parent node, state = 1: Must purchase
18            // parent node
19            auto dp0 = vector(budget + 1, 0);
20            auto dp1 = vector(budget + 1, 0);
21
22            // subProfit[state][budget]
23            // state = 0: discount not available, state = 1: discount available
24            auto subProfit0 = vector(budget + 1, 0);
25            auto subProfit1 = vector(budget + 1, 0);
26
27            int uSize = cost;
28
29            for (auto v : g[u]) {
30                auto [subDp0, subDp1, vSize] = self(self, v);
31                uSize += vSize;
32                for (int i = budget; i >= 0; i--) {
33                    for (int sub = 0; sub <= min(vSize, i); sub++) {
34                        subProfit0[i] = max(subProfit0[i],
35                                            subProfit0[i - sub] + subDp0[sub]);
36                        subProfit1[i] = max(subProfit1[i],
37                                            subProfit1[i - sub] + subDp1[sub]);
38                    }
39                }
40            }
41
42            for (int i = 0; i <= budget; i++) {
43                dp0[i] = dp1[i] = subProfit0[i];
44
45                if (i >= dCost) {
46                    dp1[i] = max(subProfit0[i],
47                                 subProfit1[i - dCost] + future[u] - dCost);
48                }
49
50                if (i >= cost) {
51                    dp0[i] = max(subProfit0[i],
52                                 subProfit1[i - cost] + future[u] - cost);
53                }
54            }
55
56            return {dp0, dp1, uSize};
57        };
58
59        return std::get<0>(dfs(dfs, 0))[budget];
60    }
61};