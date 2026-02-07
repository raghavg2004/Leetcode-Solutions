1class Solution {
2public:
3    int minimumDeletions(string s) {
4        int n = s.length();
5        vector<int> count_a(n, 0);
6        vector<int> count_b(n, 0);
7        int b_count = 0;
8
9        // First pass: compute count_b which stores the number of
10        // 'b' characters to the left of the current position.
11        for (int i = 0; i < n; i++) {
12            count_b[i] = b_count;
13            if (s[i] == 'b') b_count++;
14        }
15
16        int a_count = 0;
17        // Second pass: compute count_a which stores the number of
18        // 'a' characters to the right of the current position
19        for (int i = n - 1; i >= 0; i--) {
20            count_a[i] = a_count;
21            if (s[i] == 'a') a_count++;
22        }
23
24        int min_deletions = n;
25        // Third pass: iterate through the string to find the minimum deletions
26        for (int i = 0; i < n; i++) {
27            min_deletions = min(min_deletions, count_a[i] + count_b[i]);
28        }
29
30        return min_deletions;
31    }
32};