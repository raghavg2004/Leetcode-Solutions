class Solution {
public:
    int romanToInt(string s) {
        // Array for fast lookup (ASCII indexed). Since all Roman chars are uppercase (65–77)
        int roman[128];
        roman['I'] = 1;
        roman['V'] = 5;
        roman['X'] = 10;
        roman['L'] = 50;
        roman['C'] = 100;
        roman['D'] = 500;
        roman['M'] = 1000;

        int total = 0;

        for (int i = 0; i < s.length(); ++i) {
            // If next value is greater, subtract current; else, add current
            if (i + 1 < s.length() && roman[s[i]] < roman[s[i + 1]]) {
                total -= roman[s[i]];
            } else {
                total += roman[s[i]];
            }
        }

        return total;
    }
};
