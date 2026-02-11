1struct LazyTag {
2    int to_add = 0;
3
4    LazyTag& operator+=(const LazyTag& other) {
5        this->to_add += other.to_add;
6        return *this;
7    }
8
9    bool has_tag() const { return to_add != 0; }
10
11    void clear() { to_add = 0; }
12};
13
14struct SegmentTreeNode {
15    int min_value = 0;
16    int max_value = 0;
17    // int data = 0; // only leaf nodes are used, this question does not require
18    // it.
19    LazyTag lazy_tag;
20};
21
22class SegmentTree {
23public:
24    int n;
25    vector<SegmentTreeNode> tree;
26
27    SegmentTree(const vector<int>& data) : n(data.size()) {
28        tree.resize(n * 4 + 1);
29        build(data, 1, n, 1);
30    }
31
32    void add(int l, int r, int val) {
33        LazyTag tag{val};
34        update(l, r, tag, 1, n, 1);
35    }
36
37    int find_last(int start, int val) {
38        if (start > n) {
39            return -1;
40        }
41        return find(start, n, val, 1, n, 1);
42    }
43
44private:
45    inline void apply_tag(int i, const LazyTag& tag) {
46        tree[i].min_value += tag.to_add;
47        tree[i].max_value += tag.to_add;
48        tree[i].lazy_tag += tag;
49    }
50
51    inline void pushdown(int i) {
52        if (tree[i].lazy_tag.has_tag()) {
53            LazyTag tag = tree[i].lazy_tag;
54            apply_tag(i << 1, tag);
55            apply_tag(i << 1 | 1, tag);
56            tree[i].lazy_tag.clear();
57        }
58    }
59
60    inline void pushup(int i) {
61        tree[i].min_value =
62            std::min(tree[i << 1].min_value, tree[i << 1 | 1].min_value);
63        tree[i].max_value =
64            std::max(tree[i << 1].max_value, tree[i << 1 | 1].max_value);
65    }
66
67    void build(const vector<int>& data, int l, int r, int i) {
68        if (l == r) {
69            tree[i].min_value = tree[i].max_value = data[l - 1];
70            return;
71        }
72
73        int mid = l + ((r - l) >> 1);
74        build(data, l, mid, i << 1);
75        build(data, mid + 1, r, i << 1 | 1);
76
77        pushup(i);
78    }
79
80    void update(int target_l, int target_r, const LazyTag& tag, int l, int r,
81                int i) {
82        if (target_l <= l && r <= target_r) {
83            apply_tag(i, tag);
84            return;
85        }
86
87        pushdown(i);
88        int mid = l + ((r - l) >> 1);
89        if (target_l <= mid) update(target_l, target_r, tag, l, mid, i << 1);
90        if (target_r > mid)
91            update(target_l, target_r, tag, mid + 1, r, i << 1 | 1);
92        pushup(i);
93    }
94
95    int find(int target_l, int target_r, int val, int l, int r, int i) {
96        if (tree[i].min_value > val || tree[i].max_value < val) {
97            return -1;
98        }
99
100        // according to the Intermediate Value Theorem, there must be a solution
101        // within this interval.
102        if (l == r) {
103            return l;
104        }
105
106        pushdown(i);
107        int mid = l + ((r - l) >> 1);
108
109        // target_l is definitely less than or equal to r (=n)
110        if (target_r >= mid + 1) {
111            int res = find(target_l, target_r, val, mid + 1, r, i << 1 | 1);
112            if (res != -1) return res;
113        }
114
115        if (l <= target_r && mid >= target_l) {
116            return find(target_l, target_r, val, l, mid, i << 1);
117        }
118
119        return -1;
120    }
121};
122
123class Solution {
124public:
125    int longestBalanced(vector<int>& nums) {
126        map<int, queue<int>> occurrences;
127        auto sgn = [](int x) { return (x % 2) == 0 ? 1 : -1; };
128
129        int len = 0;
130        vector<int> prefix_sum(nums.size(), 0);
131
132        prefix_sum[0] = sgn(nums[0]);
133        occurrences[nums[0]].push(1);
134
135        for (int i = 1; i < nums.size(); i++) {
136            prefix_sum[i] = prefix_sum[i - 1];
137            auto& occ = occurrences[nums[i]];
138            if (occ.empty()) {
139                prefix_sum[i] += sgn(nums[i]);
140            }
141            occ.push(i + 1);
142        }
143
144        SegmentTree seg(prefix_sum);
145
146        for (int i = 0; i < nums.size(); i++) {
147            len = std::max(len, seg.find_last(i + len, 0) - i);
148
149            auto next_pos = nums.size() + 1;
150            occurrences[nums[i]].pop();
151            if (!occurrences[nums[i]].empty()) {
152                next_pos = occurrences[nums[i]].front();
153            }
154
155            seg.add(i + 1, next_pos - 1, -sgn(nums[i]));
156        }
157
158        return len;
159    }
160};