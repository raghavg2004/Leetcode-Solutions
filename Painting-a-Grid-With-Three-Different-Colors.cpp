class Solution {
public:
    const int MOD = 1e9 + 7;
    
    int colorTheGrid(int m, int n) {
        vector<vector<int>> valid_states;
        vector<int> curr;

        // Generate all valid single-column colorings
        function<void(int)> generate = [&](int row) {
            if (row == m) {
                valid_states.push_back(curr);
                return;
            }
            for (int color = 0; color < 3; ++color) {
                if (row == 0 || color != curr.back()) {
                    curr.push_back(color);
                    generate(row + 1);
                    curr.pop_back();
                }
            }
        };
        
        generate(0);

        int state_count = valid_states.size();
        vector<vector<int>> compatible(state_count);

        // Precompute which states are compatible
        for (int i = 0; i < state_count; ++i) {
            for (int j = 0; j < state_count; ++j) {
                bool ok = true;
                for (int k = 0; k < m; ++k) {
                    if (valid_states[i][k] == valid_states[j][k]) {
                        ok = false;
                        break;
                    }
                }
                if (ok) compatible[i].push_back(j);
            }
        }

        vector<int> dp(state_count, 1); // For the first column, each valid state is 1 way
        vector<int> new_dp(state_count);

        for (int col = 1; col < n; ++col) {
            fill(new_dp.begin(), new_dp.end(), 0);
            for (int i = 0; i < state_count; ++i) {
                for (int j : compatible[i]) {
                    new_dp[i] = (new_dp[i] + dp[j]) % MOD;
                }
            }
            dp.swap(new_dp);
        }

        int result = 0;
        for (int val : dp) {
            result = (result + val) % MOD;
        }
        return result;
    }
};
