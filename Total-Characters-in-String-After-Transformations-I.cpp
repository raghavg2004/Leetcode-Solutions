class Solution {
public:
    static constexpr int MOD = 1e9 + 7;

    int lengthAfterTransformations(string s, int t) {
        // dp[c][k] = length of result from char c after k transformations
        vector<vector<int>> dp(26, vector<int>(t + 1, 0));

        // base case: 0 transformations → length is 1
        for (int i = 0; i < 26; ++i) {
            dp[i][0] = 1;
        }

        // fill DP table
        for (int k = 1; k <= t; ++k) {
            for (int i = 0; i < 26; ++i) {
                if (i == 25) { // 'z'
                    dp[i][k] = (dp[0][k - 1] + dp[1][k - 1]) % MOD; // 'a' and 'b'
                } else {
                    dp[i][k] = dp[i + 1][k - 1];
                }
            }
        }

        // compute result
        long long total = 0;
        for (char c : s) {
            total = (total + dp[c - 'a'][t]) % MOD;
        }

        return static_cast<int>(total);
    }
};