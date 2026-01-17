1class Solution {
2public:
3    long long largestSquareArea(vector<vector<int>>& bottomLeft,
4                                vector<vector<int>>& topRight) {
5        int n = bottomLeft.size();
6        int maxSide = 0;
7
8        for (int i = 0; i < n; i++) {
9            for (int j = i + 1; j < n; j++) {
10                int w = min(topRight[i][0], topRight[j][0]) -
11                        max(bottomLeft[i][0], bottomLeft[j][0]);
12                int h = min(topRight[i][1], topRight[j][1]) -
13                        max(bottomLeft[i][1], bottomLeft[j][1]);
14
15                maxSide = max(maxSide, min(w, h));
16            }
17        }
18
19        return 1LL * maxSide * maxSide;
20    }
21};