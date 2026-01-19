1class Solution {
2public:
3    int getRect(const vector<vector<int>>& P, int x1, int y1, int x2, int y2) {
4        return P[x2][y2] - P[x1 - 1][y2] - P[x2][y1 - 1] + P[x1 - 1][y1 - 1];
5    }
6
7    int maxSideLength(vector<vector<int>>& mat, int threshold) {
8        int m = mat.size(), n = mat[0].size();
9        vector<vector<int>> P(m + 1, vector<int>(n + 1));
10        for (int i = 1; i <= m; ++i) {
11            for (int j = 1; j <= n; ++j) {
12                P[i][j] = P[i - 1][j] + P[i][j - 1] - P[i - 1][j - 1] +
13                          mat[i - 1][j - 1];
14            }
15        }
16
17        int l = 1, r = min(m, n), ans = 0;
18        while (l <= r) {
19            int mid = (l + r) / 2;
20            bool find = false;
21            for (int i = 1; i <= m - mid + 1; ++i) {
22                for (int j = 1; j <= n - mid + 1; ++j) {
23                    if (getRect(P, i, j, i + mid - 1, j + mid - 1) <=
24                        threshold) {
25                        find = true;
26                    }
27                }
28            }
29            if (find) {
30                ans = mid;
31                l = mid + 1;
32            } else {
33                r = mid - 1;
34            }
35        }
36        return ans;
37    }
38};