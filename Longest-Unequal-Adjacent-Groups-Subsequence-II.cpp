class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> dp(n, 1);         // Length of longest valid subsequence ending at i
        vector<int> parent(n, -1);    // For path reconstruction

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (groups[i] != groups[j] &&
                    words[i].length() == words[j].length() &&
                    hammingDistOne(words[i], words[j])) {
                    
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        parent[i] = j;
                    }
                }
            }
        }

        // Find the end index of the longest path
        int maxLen = 0, idx = -1;
        for (int i = 0; i < n; ++i) {
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                idx = i;
            }
        }

        // Reconstruct the subsequence
        vector<string> result;
        while (idx != -1) {
            result.push_back(words[idx]);
            idx = parent[idx];
        }

        reverse(result.begin(), result.end());
        return result;
    }

private:
    bool hammingDistOne(const string& a, const string& b) {
        int diff = 0;
        for (int i = 0; i < a.size(); ++i)
            if (a[i] != b[i] && ++diff > 1) return false;
        return diff == 1;
    }
};
