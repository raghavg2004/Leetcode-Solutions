1class Solution {
2public:
3    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
4        vector<int> maxRow(n + 1);
5        vector<int> minRow(n + 1, n + 1);
6        vector<int> maxCol(n + 1);
7        vector<int> minCol(n + 1, n + 1);
8
9        for (auto& p : buildings) {
10            int x = p[0], y = p[1];
11            maxRow[y] = max(maxRow[y], x);
12            minRow[y] = min(minRow[y], x);
13            maxCol[x] = max(maxCol[x], y);
14            minCol[x] = min(minCol[x], y);
15        }
16
17        int res = 0;
18        for (auto& p : buildings) {
19            int x = p[0], y = p[1];
20            if (x > minRow[y] && x < maxRow[y] && y > minCol[x] &&
21                y < maxCol[x]) {
22                res++;
23            }
24        }
25
26        return res;
27    }
28};