1class Solution {
2    unordered_set<int> getEdges(vector<int>& fences, int border) {
3        unordered_set<int> st;
4        fences.push_back(1);
5        fences.push_back(border);
6        sort(fences.begin(), fences.end());
7        for (int i = 0; i < fences.size(); i++) {
8            for (int j = i + 1; j < fences.size(); j++) {
9                st.insert(fences[j] - fences[i]);
10            }
11        }
12        return st;
13    }
14
15public:
16    int maximizeSquareArea(int m, int n, vector<int>& hFences,
17                           vector<int>& vFences) {
18        auto hEdges = getEdges(hFences, m);
19        auto vEdges = getEdges(vFences, n);
20        int res = 0;
21        for (auto e : hEdges) {
22            if (vEdges.contains(e)) {
23                res = max(res, e);
24            }
25        }
26        if (res == 0) {
27            res = -1;
28        } else {
29            res = 1ll * res * res % 1000000007;
30        }
31        return res;
32    }
33};