class Solution {
public:
    string robotWithString(string s) {
        int n = s.length();
        vector<char> min_suffix(n);
        min_suffix[n - 1] = s[n - 1];

        // Fill min_suffix[i] with min char from s[i:] (inclusive)
        for (int i = n - 2; i >= 0; --i) {
            min_suffix[i] = min(s[i], min_suffix[i + 1]);
        }

        stack<char> t;
        string result;

        for (int i = 0; i < n; ++i) {
            t.push(s[i]);
            
            // Pop from t to result while top of t <= smallest char left in s
            while (!t.empty() && (i == n - 1 || t.top() <= min_suffix[i + 1])) {
                result += t.top();
                t.pop();
            }
        }

        // Empty any remaining characters in stack t
        while (!t.empty()) {
            result += t.top();
            t.pop();
        }

        return result;
    }
};
