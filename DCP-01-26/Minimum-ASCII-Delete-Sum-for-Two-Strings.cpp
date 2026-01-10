1class Solution {
2public:
3    int dp[1001][1001];
4
5    int solve(string& s1, string& s2, int i, int j) {
6        if (i >= s1.size() && j >= s2.size()) {
7            return 0;
8        }
9
10        if (i >= s1.size()) {
11            int sum = 0;
12            for (int k = j; k < s2.size(); k++) {
13                sum += (int)s2[k];
14            }
15            return sum;
16        }
17
18        if (j >= s2.size()) {
19            int sum = 0;
20            for (int k = i; k < s1.size(); k++) {
21                sum += (int)s1[k];
22            }
23            return sum;
24        }
25
26        if (dp[i][j] != -1) return dp[i][j];
27
28        int ans;
29        if (s1[i] == s2[j]) {
30            ans = solve(s1, s2, i + 1, j + 1);
31        } else {
32            int deleteS1 = (int)s1[i] + solve(s1, s2, i + 1, j);
33            int deleteS2 = (int)s2[j] + solve(s1, s2, i, j + 1);
34            ans = min(deleteS1, deleteS2);
35        }
36
37        return dp[i][j] = ans;
38    }
39
40    int minimumDeleteSum(string s1, string s2) {
41        memset(dp, -1, sizeof(dp));
42        return solve(s1, s2, 0, 0);
43    }
44};