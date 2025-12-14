1class Solution {
2public:
3    // Store 1000000007 in a variable for convenience
4    const int MOD = 1e9 + 7;
5    
6    // Count the number of ways to divide from "index" to the last index
7    // with "seats" number of "S" in the current section
8    int count(int index, int seats, string& corridor, int cache[][3]) {
9        // If we have reached the end of the corridor, then
10        // the current section is valid only if "seats" is 2
11        if (index == corridor.length()) {
12            return seats == 2 ? 1 : 0;
13        }
14
15        // If we have already computed the result of this sub-problem,
16        // then return the cached result
17        if (cache[index][seats] != -1) {
18            return cache[index][seats];
19        }
20
21        // Result of the sub-problem
22        int result = 0;
23
24        // If the current section has exactly 2 "S"
25        if (seats == 2) {
26            // If the current element is "S", then we have to close the
27            // section and start a new section from this index. Next index
28            // will have one "S" in the current section
29            if (corridor[index] == 'S') {
30                result = count(index + 1, 1, corridor, cache);
31            } else {
32                // If the current element is "P", then we have two options
33                // 1. Close the section and start a new section from this index
34                // 2. Keep growing the section
35                result = (count(index + 1, 0, corridor, cache) + count(index + 1, 2, corridor, cache)) % MOD;  
36            }
37        } else {
38            // Keep growing the section. Increment "seats" if present
39            // element is "S"
40            if (corridor[index] == 'S') {
41                result = count(index + 1, seats + 1, corridor, cache);
42            } else {
43                result = count(index + 1, seats, corridor, cache);
44            }
45        }
46
47        // Memoize the result, and return it
48        cache[index][seats] = result;
49        return cache[index][seats];
50    }
51
52    int numberOfWays(string corridor) {
53        // Cache the result of each sub-problem
54        int cache[corridor.length()][3];
55        memset(cache, -1, sizeof(cache));
56
57        // Call the count function
58        return count(0, 0, corridor, cache);
59    }
60};