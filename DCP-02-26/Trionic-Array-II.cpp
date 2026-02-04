1class Solution {
2public:
3    long long maxSumTrionic(vector<int>& nums) {
4        int n = nums.size();
5        int p, q, j;
6        long long max_sum, sum, res;
7        long long ans = LLONG_MIN;
8        for (int i = 0; i < n; i++) {
9            j = i + 1;
10            res = 0;
11            // first segment
12            for (; j < n && nums[j - 1] < nums[j]; j++);
13            p = j - 1;
14            if (p == i) {
15                continue;
16            }
17            // second segment
18            res += nums[p] + nums[p - 1];
19            for (; j < n && nums[j - 1] > nums[j]; j++) {
20                res += nums[j];
21            }
22            q = j - 1;
23            if (q == p || q == n - 1 || (nums[j] <= nums[q])) {
24                i = q;
25                continue;
26            }
27            // third segment
28            res += nums[q + 1];
29            // find the maximum sum of the third segment
30            max_sum = 0;
31            sum = 0;
32            for (int k = q + 2; k < n && nums[k] > nums[k - 1]; k++) {
33                sum += nums[k];
34                max_sum = max(max_sum, sum);
35            }
36            res += max_sum;
37            // find the maximum sum of the first segment
38            max_sum = 0;
39            sum = 0;
40            for (int k = p - 2; k >= i; k--) {
41                sum += nums[k];
42                max_sum = max(max_sum, sum);
43            }
44            res += max_sum;
45            // update answer
46            ans = max(ans, res);
47            i = q - 1;
48        }
49        return ans;
50    }
51};