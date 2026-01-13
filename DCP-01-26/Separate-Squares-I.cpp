1class Solution {
2public:
3    double separateSquares(vector<vector<int>>& squares) {
4        double max_y = 0, total_area = 0;
5        for (auto& sq : squares) {
6            int y = sq[1], l = sq[2];
7            total_area += (double)l * l;
8            max_y = max(max_y, (double)(y + l));
9        }
10
11        auto check = [&](double limit_y) -> bool {
12            double area = 0;
13            for (auto& sq : squares) {
14                int y = sq[1], l = sq[2];
15                if (y < limit_y) {
16                    area += l * min(limit_y - y, (double)l);
17                }
18            }
19            return area >= total_area / 2;
20        };
21
22        double lo = 0, hi = max_y;
23        double eps = 1e-5;
24        while (abs(hi - lo) > eps) {
25            double mid = (hi + lo) / 2;
26            if (check(mid)) {
27                hi = mid;
28            } else {
29                lo = mid;
30            }
31        }
32        return hi;
33    }
34};