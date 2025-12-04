1class Solution {
2public:
3    int countCollisions(string directions) {
4        int res = 0;
5        int flag = -1;
6        for (auto c : directions) {
7            if (c == 'L') {
8                if (flag >= 0) {
9                    res += flag + 1;
10                    flag = 0;
11                }
12            } else if (c == 'S') {
13                if (flag > 0) {
14                    res += flag;
15                }
16                flag = 0;
17            } else {
18                if (flag >= 0) {
19                    flag++;
20                } else {
21                    flag = 1;
22                }
23            }
24        }
25        return res;
26    }
27};