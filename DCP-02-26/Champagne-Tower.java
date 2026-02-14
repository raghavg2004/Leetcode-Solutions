1class Solution {
2    public double champagneTower(int poured, int query_row, int query_glass) {
3        double[][] A = new double[102][102];
4        A[0][0] = (double) poured;
5        for (int r = 0; r <= query_row; ++r) {
6            for (int c = 0; c <= r; ++c) {
7                double q = (A[r][c] - 1.0) / 2.0;
8                if (q > 0) {
9                    A[r+1][c] += q;
10                    A[r+1][c+1] += q;
11                }
12            }
13        }
14
15        return Math.min(1, A[query_row][query_glass]);
16    }
17}