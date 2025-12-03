1class Solution {
2public:
3    int countTrapezoids(vector<vector<int>>& points) {
4        int n = points.size();
5        int inf = 1e9 + 7;
6        unordered_map<float, vector<float>> slopeToIntercept;
7        unordered_map<int, vector<float>> midToSlope;
8        int ans = 0;
9        for (int i = 0; i < n; i++) {
10            int x1 = points[i][0];
11            int y1 = points[i][1];
12            for (int j = i + 1; j < n; j++) {
13                int x2 = points[j][0];
14                int y2 = points[j][1];
15                int dx = x1 - x2;
16                int dy = y1 - y2;
17                float k, b;
18                if (x2 == x1) {
19                    k = inf;
20                    b = x1;
21                } else {
22                    k = (float)(y2 - y1) / (x2 - x1);
23                    b = (float)(y1 * dx - x1 * dy) / dx;
24                }
25                int mid = (x1 + x2) * 10000 + (y1 + y2);
26                slopeToIntercept[k].push_back(b);
27                midToSlope[mid].push_back(k);
28            }
29        }
30        for (auto& [_, sti] : slopeToIntercept) {
31            if (sti.size() == 1) {
32                continue;
33            }
34            map<float, int> cnt;
35            for (float b : sti) {
36                cnt[b]++;
37            }
38            int sum = 0;
39            for (auto& [_, count] : cnt) {
40                ans += sum * count;
41                sum += count;
42            }
43        }
44        for (auto& [_, mts] : midToSlope) {
45            if (mts.size() == 1) {
46                continue;
47            }
48            map<float, int> cnt;
49            for (float k : mts) {
50                cnt[k]++;
51            }
52            int sum = 0;
53            for (auto& [_, count] : cnt) {
54                ans -= sum * count;
55                sum += count;
56            }
57        }
58        return ans;
59    }
60};