class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        
        // For maximum: replace the first digit (not 9) with 9
        string a = s;
        for (char c : s) {
            if (c != '9') {
                for (char& ch : a) {
                    if (ch == c) ch = '9';
                }
                break;
            }
        }

        // For minimum: replace the first digit (not 1) with 1 if it's the first digit,
        // else replace any other digit (not 0 or 1) with 0
        string b = s;
        if (s[0] != '1') {
            char c = s[0];
            for (char& ch : b) {
                if (ch == c) ch = '1';
            }
        } else {
            for (int i = 1; i < s.size(); ++i) {
                if (s[i] != '0' && s[i] != '1') {
                    char c = s[i];
                    for (char& ch : b) {
                        if (ch == c) ch = '0';
                    }
                    break;
                }
            }
        }

        return stoi(a) - stoi(b);
    }
};
