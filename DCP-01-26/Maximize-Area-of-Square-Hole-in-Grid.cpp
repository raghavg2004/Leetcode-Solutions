1class Solution {
2public:
3    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars,
4                               vector<int>& vBars) {
5        sort(hBars.begin(), hBars.end());
6        sort(vBars.begin(), vBars.end());
7        int hmax = 1, vmax = 1;
8        int hcur = 1, vcur = 1;
9        for (int i = 1; i < hBars.size(); i++) {
10            if (hBars[i] == hBars[i - 1] + 1) {
11                hcur++;
12            } else {
13                hcur = 1;
14            }
15            hmax = max(hmax, hcur);
16        }
17        for (int i = 1; i < vBars.size(); i++) {
18            if (vBars[i] == vBars[i - 1] + 1) {
19                vcur++;
20            } else {
21                vcur = 1;
22            }
23            vmax = max(vmax, vcur);
24        }
25        int side = min(hmax, vmax) + 1;
26        return side * side;
27    }
28};