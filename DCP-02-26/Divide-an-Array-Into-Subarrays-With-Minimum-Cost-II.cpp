1// two multisets maintain the first k smallest values
2class Container {
3public:
4    Container(int k) : k(k), sm(0) {}
5
6    // adjust the size of the ordered set to ensure that the first k smallest
7    // values are all in st1
8    void adjust() {
9        while (st1.size() < k && st2.size() > 0) {
10            int x = *(st2.begin());
11            st1.emplace(x);
12            sm += x;
13            st2.erase(st2.begin());
14        }
15        while (st1.size() > k) {
16            int x = *prev(st1.end());
17            st2.emplace(x);
18            st1.erase(prev(st1.end()));
19            sm -= x;
20        }
21    }
22
23    // insert element x
24    void add(int x) {
25        if (!st2.empty() && x >= *(st2.begin())) {
26            st2.emplace(x);
27        } else {
28            st1.emplace(x);
29            sm += x;
30        }
31        adjust();
32    }
33
34    // delete element x
35    void erase(int x) {
36        auto it = st1.find(x);
37        if (it != st1.end()) {
38            st1.erase(it), sm -= x;
39        } else {
40            st2.erase(st2.find(x));
41        }
42        adjust();
43    }
44
45    // sum of the first k smallest elements
46    long long sum() { return sm; }
47
48private:
49    int k;
50    // st1 saves the k smallest values, st2 saves the other values
51    multiset<int> st1, st2;
52    // sm represents the sum of the first k smallest elements
53    long long sm;
54};
55
56class Solution {
57public:
58    long long minimumCost(vector<int>& nums, int k, int dist) {
59        int n = nums.size();
60        // sliding window initialization
61        Container cnt(k - 2);
62        for (int i = 1; i < k - 1; i++) {
63            cnt.add(nums[i]);
64        }
65
66        long long ans = cnt.sum() + nums[k - 1];
67        // enumerate the beginning of the last array
68        for (int i = k; i < n; i++) {
69            int j = i - dist - 1;
70            if (j > 0) {
71                cnt.erase(nums[j]);
72            }
73            cnt.add(nums[i - 1]);
74            ans = min(ans, cnt.sum() + nums[i]);
75        }
76
77        return ans + nums[0];
78    }
79};