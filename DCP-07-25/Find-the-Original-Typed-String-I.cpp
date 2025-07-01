class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.length();
        int count = 1; // original string is always valid
        int i = 0;

        while (i < n) {
            int j = i;
            while (j < n && word[j] == word[i]) j++;

            int len = j - i;
            if (len > 1) {
                count += (len - 1); // can remove 1 to len-1 chars from this group
            }

            i = j;
        }

        return count;
    }
};
