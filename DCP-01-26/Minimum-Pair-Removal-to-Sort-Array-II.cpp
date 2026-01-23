1typedef long long ll;
2
3const int MAX_N = 100005;
4
5struct Node {
6    ll value;
7    int left;
8};
9
10using ListIt = std::list<Node>::iterator;
11
12struct Pair {
13    ListIt first;
14    ListIt second;
15    ll cost;
16    size_t firstLeft;
17    size_t secondLeft;
18
19    Pair() {}
20    Pair(ListIt fi, ListIt se, ll cost)
21        : first(fi),
22          second(se),
23          firstLeft(fi->left),
24          secondLeft(se->left),
25          cost(cost) {}
26};
27
28struct ComparePair {
29    bool operator()(const Pair& a, const Pair& b) {
30        if (a.cost != b.cost) {
31            return a.cost > b.cost;
32        }
33        return a.firstLeft > b.firstLeft;
34    }
35};
36
37class Solution {
38public:
39    int minimumPairRemoval(std::vector<int>& nums) {
40        std::list<Node> list;
41        std::bitset<MAX_N> merged;
42        std::priority_queue<Pair, std::vector<Pair>, ComparePair> pq;
43
44        int decreaseCount = 0;
45        int count = 0;
46
47        list.push_back({nums[0], 0});
48
49        for (size_t i = 1; i < nums.size(); ++i) {
50            list.push_back({nums[i], (int)i});
51
52            auto curr = std::prev(list.end());
53            auto prev = std::prev(curr);
54
55            pq.push({prev, curr, prev->value + curr->value});
56
57            if (nums[i - 1] > nums[i]) {
58                decreaseCount++;
59            }
60        }
61
62        while (decreaseCount > 0 && !pq.empty()) {
63            auto top = pq.top();
64            pq.pop();
65
66            if (merged[top.firstLeft] || merged[top.secondLeft]) {
67                continue;
68            }
69
70            auto first = top.first;
71            auto second = top.second;
72            auto cost = top.cost;
73
74            if (first->value + second->value != cost) {
75                continue;
76            }
77
78            count++;
79
80            if (first->value > second->value) {
81                decreaseCount--;
82            }
83
84            ListIt prev =
85                (first == list.begin()) ? list.end() : std::prev(first);
86            ListIt next = std::next(second);
87
88            if (prev != list.end()) {
89                if (prev->value > first->value && prev->value <= cost) {
90                    decreaseCount--;
91                }
92                if (prev->value <= first->value && prev->value > cost) {
93                    decreaseCount++;
94                }
95                pq.push({prev, first, prev->value + cost});
96            }
97
98            if (next != list.end()) {
99                if (second->value > next->value && cost <= next->value) {
100                    decreaseCount--;
101                }
102                if (second->value <= next->value && cost > next->value) {
103                    decreaseCount++;
104                }
105                pq.push({first, next, cost + next->value});
106            }
107
108            first->value = cost;
109            merged[second->left] = 1;
110            list.erase(second);
111        }
112
113        return count;
114    }
115};