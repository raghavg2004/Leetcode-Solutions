1class Solution {
2    using PII = pair<int, int>;
3
4public:
5    int minCost(int n, vector<vector<int>>& edges) {
6        vector<vector<PII>> g(n);
7        for (auto& e : edges) {
8            int x = e[0], y = e[1], w = e[2];
9            g[x].emplace_back(y, w);
10            g[y].emplace_back(x, 2 * w);
11        }
12
13        vector<int> d(n, INT_MAX);
14        vector<bool> v(n, false);
15        priority_queue<PII, vector<PII>, greater<PII>> q;
16        d[0] = 0;
17        q.emplace(0, 0);
18
19        while (!q.empty()) {
20            int x = q.top().second;
21            q.pop();
22            if (x == n - 1) {
23                return d[x];
24            }
25            // only the first time unloading requires relaxing other points
26            if (v[x]) {
27                continue;
28            }
29            v[x] = 1;
30
31            for (auto& [y, w] : g[x]) {
32                if (d[x] + w < d[y]) {
33                    d[y] = d[x] + w;
34                    q.emplace(d[y], y);
35                }
36            }
37        }
38        return -1;
39    }
40};