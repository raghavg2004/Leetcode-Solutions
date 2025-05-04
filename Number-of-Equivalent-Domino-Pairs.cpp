class Solution {
public:
    // Function to remove adjacent duplicates from the string.
    string removeDuplicates(string s) {
        int j = 0; // Pointer to track the position of the valid string (result)

        // Traverse the string s character by character
        for (int i = 0; i < s.length(); i++) {
            // Check if the current character is equal to the previous character
            // If it is, we remove the last character (i.e., backtrack)
            if (j > 0 && s[i] == s[j - 1]) {
                j--;  // Remove the last character (backtrack by decreasing the index)
            } else {
                // Otherwise, keep the character in the valid result string
                s[j] = s[i];  // Place the current character at the correct position
                j++;  // Move the pointer forward to the next position
            }
        }

        // After processing all characters, the string from 0 to j is the final result
        return s.substr(0, j);  // Return the substring of valid characters
    }
};