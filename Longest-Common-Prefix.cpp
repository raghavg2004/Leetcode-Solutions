class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // If the input vector is empty, return empty string
        if (strs.empty()) return \\;

        // Start with the first string as the initial prefix
        string prefix = strs[0];

        // Compare the prefix with each string in the vector
        for (int i = 1; i < strs.size(); ++i) {
            // Reduce the prefix until it matches the beginning of strs[i]
            while (strs[i].find(prefix) != 0) {
                prefix.pop_back(); // Remove last character
                if (prefix.empty()) return \\; // No common prefix
            }
        }

        return prefix;
    }
};
