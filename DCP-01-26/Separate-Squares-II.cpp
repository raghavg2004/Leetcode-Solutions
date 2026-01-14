1class SegmentTree {
2private:
3    vector<int> count;
4    vector<int> covered;
5    vector<int> xs;
6    int n;
7
8    void modify(int qleft, int qright, int qval, int left, int right, int pos) {
9        if (xs[right + 1] <= qleft || xs[left] >= qright) {
10            return;
11        }
12        if (qleft <= xs[left] && xs[right + 1] <= qright) {
13            count[pos] += qval;
14        } else {
15            int mid = (left + right) / 2;
16            modify(qleft, qright, qval, left, mid, pos * 2 + 1);
17            modify(qleft, qright, qval, mid + 1, right, pos * 2 + 2);
18        }
19
20        if (count[pos] > 0) {
21            covered[pos] = xs[right + 1] - xs[left];
22        } else {
23            if (left == right) {
24                covered[pos] = 0;
25            } else {
26                covered[pos] = covered[pos * 2 + 1] + covered[pos * 2 + 2];
27            }
28        }
29    }
30
31public:
32    SegmentTree(vector<int>& xs_) : xs(xs_) {
33        n = xs.size() - 1;
34        count.resize(4 * n, 0);
35        covered.resize(4 * n, 0);
36    }
37
38    void update(int qleft, int qright, int qval) {
39        modify(qleft, qright, qval, 0, n - 1, 0);
40    }
41
42    int query() { return covered[0]; }
43};
44
45class Solution {
46public:
47    double separateSquares(vector<vector<int>>& squares) {
48        vector<tuple<int, int, int, int>> events;
49        set<int> xsSet;
50
51        for (auto& sq : squares) {
52            int x = sq[0], y = sq[1], l = sq[2];
53            int xr = x + l;
54            events.emplace_back(y, 1, x, xr);
55            events.emplace_back(y + l, -1, x, xr);
56            xsSet.insert(x);
57            xsSet.insert(xr);
58        }
59
60        // sort events by y-coordinate
61        sort(events.begin(), events.end());
62        // discrete coordinates
63        vector<int> xs(xsSet.begin(), xsSet.end());
64        // initialize the segment tree
65        SegmentTree segTree(xs);
66
67        vector<double> psum;
68        vector<int> widths;
69        double total_area = 0.0;
70        int prev = get<0>(events[0]);
71
72        // scan: calculate total area and record intermediate states
73        for (auto& [y, delta, xl, xr] : events) {
74            int len = segTree.query();
75            total_area += 1LL * len * (y - prev);
76            segTree.update(xl, xr, delta);
77            // record prefix sums and widths
78            psum.push_back(total_area);
79            widths.push_back(segTree.query());
80            prev = y;
81        }
82
83        // calculate the target area (half rounded up)
84        long long target = (long long)(total_area + 1) / 2;
85        // find the first position greater than or equal to target using binary
86        // search
87        int i =
88            lower_bound(psum.begin(), psum.end(), target) - psum.begin() - 1;
89        // get the corresponding area, width, and height
90        double area = psum[i];
91        int width = widths[i], height = get<0>(events[i]);
92
93        return height + (total_area - area * 2) / (width * 2.0);
94    }
95};