1class Solution {
2public:
3    int minCost(vector<vector<int>>& grid, int k) {
4        int m = grid.size(), n = grid[0].size();
5        vector<pair<int, int>> points;
6        for (int i = 0; i < m; i++) {
7            for (int j = 0; j < n; j++) {
8                points.push_back({i, j});
9            }
10        }
11        sort(points.begin(), points.end(),
12             [&](const auto& p1, const auto& p2) -> bool {
13                 return grid[p1.first][p1.second] < grid[p2.first][p2.second];
14             });
15        vector<vector<int>> costs(m, vector<int>(n, INT_MAX));
16        for (int t = 0; t <= k; t++) {
17            int minCost = INT_MAX;
18            for (int i = 0, j = 0; i < points.size(); i++) {
19                minCost =
20                    min(minCost, costs[points[i].first][points[i].second]);
21                if (i + 1 < points.size() &&
22                    grid[points[i].first][points[i].second] ==
23                        grid[points[i + 1].first][points[i + 1].second]) {
24                    continue;
25                }
26                for (int r = j; r <= i; r++) {
27                    costs[points[r].first][points[r].second] = minCost;
28                }
29                j = i + 1;
30            }
31            for (int i = m - 1; i >= 0; i--) {
32                for (int j = n - 1; j >= 0; j--) {
33                    if (i == m - 1 && j == n - 1) {
34                        costs[i][j] = 0;
35                        continue;
36                    }
37                    if (i != m - 1) {
38                        costs[i][j] =
39                            min(costs[i][j], costs[i + 1][j] + grid[i + 1][j]);
40                    }
41                    if (j != n - 1) {
42                        costs[i][j] =
43                            min(costs[i][j], costs[i][j + 1] + grid[i][j + 1]);
44                    }
45                }
46            }
47        }
48        return costs[0][0];
49    }
50};