1class Solution {
2public:
3    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
4        int ans = 0;
5        for (int i = 0; i < points.size() - 1; i++) {
6            int currX = points[i][0];
7            int currY = points[i][1];
8            int targetX = points[i + 1][0];
9            int targetY = points[i + 1][1];
10            ans += max(abs(targetX - currX), abs(targetY - currY));
11        }
12        
13        return ans;
14    }
15};