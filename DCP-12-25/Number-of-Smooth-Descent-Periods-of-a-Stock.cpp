1class Solution {
2public:
3    long long getDescentPeriods(vector<int>& prices) {
4        int n = prices.size();
5        long long res = 1;  // total number of smooth descending periods,
6                            // initial value is dp[0]
7        int prev = 1;  // total number of smooth descending periods ending with
8                       // the previous element, initial value is dp[0]
9        // traverse the array starting from 1, and update prev and the total res
10        // according to the recurrence relation
11        for (int i = 1; i < n; ++i) {
12            if (prices[i] == prices[i - 1] - 1) {
13                ++prev;
14            } else {
15                prev = 1;
16            }
17            res += prev;
18        }
19        return res;
20    }
21};