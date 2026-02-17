1class Solution {
2public:
3    vector<string> readBinaryWatch(int turnedOn) {
4        vector<string> ans;
5        for (int h = 0; h < 12; ++h) {
6            for (int m = 0; m < 60; ++m) {
7                if (__builtin_popcount(h) + __builtin_popcount(m) == turnedOn) {
8                    ans.push_back(to_string(h) + ":" + (m < 10 ? "0" : "") +
9                                  to_string(m));
10                }
11            }
12        }
13        return ans;
14    }
15};