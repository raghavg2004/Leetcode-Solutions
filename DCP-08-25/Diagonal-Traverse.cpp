class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> ans;
        ans.reserve(m * n);

        // There are (m + n - 1) diagonals
        for (int d = 0; d < m + n - 1; d++) {
            vector<int> temp;

            // Row starts at max(0, d - n + 1)
            int r = max(0, d - n + 1);
            // Column starts at min(d, n - 1)
            int c = min(d, n - 1);

            // Collect all elements of this diagonal
            while (r < m && c >= 0) {
                temp.push_back(mat[r][c]);
                r++;
                c--;
            }

            // Reverse every alternate diagonal
            if (d % 2 == 0) {
                reverse(temp.begin(), temp.end());
            }

            // Append to result
            ans.insert(ans.end(), temp.begin(), temp.end());
        }
        return ans;
    }
};
