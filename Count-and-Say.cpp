class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return \1\;
        
        string prev = \1\;

        for (int i = 2; i <= n; ++i) {
            string curr = \\;
            int count = 1;
            for (int j = 1; j < prev.size(); ++j) {
                if (prev[j] == prev[j - 1]) {
                    count++;
                } else {
                    curr += to_string(count) + prev[j - 1];
                    count = 1;
                }
            }
            curr += to_string(count) + prev.back(); // Add the last sequence
            prev = curr;
        }

        return prev;
    }
};
