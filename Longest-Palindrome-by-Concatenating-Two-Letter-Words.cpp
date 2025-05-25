class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> freq;
        int length = 0;
        bool hasMiddle = false;

        for (const string& word : words) {
            freq[word]++;
        }

        for (auto& [word, count] : freq) {
            string rev = string{word.rbegin(), word.rend()};

            if (word == rev) {
                // For symmetric words like "gg", "cc"
                int pairs = count / 2;
                length += pairs * 4;
                freq[word] -= pairs * 2;

                // If there's still one left, we can use it in the middle
                if (freq[word] > 0) {
                    hasMiddle = true;
                }
            } else if (freq.find(rev) != freq.end()) {
                int pairs = min(count, freq[rev]);
                length += pairs * 4;
                freq[word] -= pairs;
                freq[rev] -= pairs;
            }
        }

        if (hasMiddle) length += 2;

        return length;
    }
};
