1class Solution {
2public:
3    int longestBalanced(string s) {
4        int n = s.size();
5        int res = 0;
6        vector<int> cnt(26);
7        for (int i = 0; i < n; i++) {
8            fill(cnt.begin(), cnt.end(), 0);
9            for (int j = i; j < n; j++) {
10                bool flag = true;
11                int c = s[j] - 'a';
12                cnt[c]++;
13                for (auto x : cnt) {
14                    if (x > 0 && x != cnt[c]) {
15                        flag = false;
16                        break;
17                    }
18                }
19                if (flag) {
20                    res = max(res, j - i + 1);
21                }
22            }
23        }
24        return res;
25    }
26};