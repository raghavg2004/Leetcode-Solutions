1class Solution {
2public:
3    int largestMagicSquare(vector<vector<int>>& grid) {
4        int m = grid.size(), n = grid[0].size();
5        // prefix sum of each row
6        vector<vector<int>> rowsum(m, vector<int>(n));
7        for (int i = 0; i < m; ++i) {
8            rowsum[i][0] = grid[i][0];
9            for (int j = 1; j < n; ++j) {
10                rowsum[i][j] = rowsum[i][j - 1] + grid[i][j];
11            }
12        }
13        // prefix sum of each column
14        vector<vector<int>> colsum(m, vector<int>(n));
15        for (int j = 0; j < n; ++j) {
16            colsum[0][j] = grid[0][j];
17            for (int i = 1; i < m; ++i) {
18                colsum[i][j] = colsum[i - 1][j] + grid[i][j];
19            }
20        }
21
22        // enumerate edge lengths from largest to smallest
23        for (int edge = min(m, n); edge >= 2; --edge) {
24            // enumerate the top-left corner position (i,j) of the square
25            for (int i = 0; i + edge <= m; ++i) {
26                for (int j = 0; j + edge <= n; ++j) {
27                    // the value for each row, column, and diagonal should be
28                    // calculated (using the first row as a sample)
29                    int stdsum =
30                        rowsum[i][j + edge - 1] - (j ? rowsum[i][j - 1] : 0);
31                    bool check = true;
32                    // enumerate each row and directly compute the sum using
33                    // prefix sums since we have already used the first line as
34                    // a sample, we can skip the first line here.
35                    for (int ii = i + 1; ii < i + edge; ++ii) {
36                        if (rowsum[ii][j + edge - 1] -
37                                (j ? rowsum[ii][j - 1] : 0) !=
38                            stdsum) {
39                            check = false;
40                            break;
41                        }
42                    }
43                    if (!check) {
44                        continue;
45                    }
46                    // enumerate each column and directly calculate the sum
47                    // using prefix sums
48                    for (int jj = j; jj < j + edge; ++jj) {
49                        if (colsum[i + edge - 1][jj] -
50                                (i ? colsum[i - 1][jj] : 0) !=
51                            stdsum) {
52                            check = false;
53                            break;
54                        }
55                    }
56                    if (!check) {
57                        continue;
58                    }
59                    // d1 and d2 represent the sums of the two diagonals
60                    // respectively. here d denotes diagonal
61                    int d1 = 0, d2 = 0;
62                    // sum directly by traversing without using the prefix sum.
63                    for (int k = 0; k < edge; ++k) {
64                        d1 += grid[i + k][j + k];
65                        d2 += grid[i + k][j + edge - 1 - k];
66                    }
67                    if (d1 == stdsum && d2 == stdsum) {
68                        return edge;
69                    }
70                }
71            }
72        }
73
74        return 1;
75    }
76};