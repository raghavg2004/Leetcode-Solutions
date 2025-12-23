1class Solution {
2public:
3    int maxTwoEvents(vector<vector<int>>& events) {
4        sort(events.begin(), events.end());
5        vector<vector<int>> dp(events.size(), vector<int>(3, -1));
6        return findEvents(events, 0, 0, dp);
7    }
8    // Recursive function to find the greatest sum for the pairs.
9    int findEvents(vector<vector<int>>& events, int idx, int cnt,
10                   vector<vector<int>>& dp) {
11        if (cnt == 2 || idx >= events.size()) return 0;
12        if (dp[idx][cnt] == -1) {
13            int end = events[idx][1];
14            int lo = idx + 1, hi = events.size() - 1;
15            while (lo < hi) {
16                int mid = lo + ((hi - lo) >> 1);
17                if (events[mid][0] > end)
18                    hi = mid;
19                else
20                    lo = mid + 1;
21            }
22            int include =
23                events[idx][2] + (lo < events.size() && events[lo][0] > end
24                                      ? findEvents(events, lo, cnt + 1, dp)
25                                      : 0);
26            int exclude = findEvents(events, idx + 1, cnt, dp);
27            dp[idx][cnt] = max(include, exclude);
28        }
29        return dp[idx][cnt];
30    }
31};