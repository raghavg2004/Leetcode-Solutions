class Solution {
public:
    int maxDifference(string s) {
        vector<int> freq(26, 0);

        // Count frequencies of each character
        for (char c : s) {
            freq[c - 'a']++;
        }

        int max_odd = INT_MIN;
        int min_even = INT_MAX;

        // Find max odd frequency and min even frequency
        for (int f : freq) {
            if (f == 0) continue;

            if (f % 2 == 1) {
                max_odd = max(max_odd, f);
            } else {
                min_even = min(min_even, f);
            }
        }

        // Guaranteed by constraints that at least one odd and one even exists
        return max_odd - min_even;
    }
};
