class Solution {
public:
    bool isPowerOfFour(int n) {
        // Check if n is positive and a power of two
        if (n <= 0 || (n & (n - 1)) != 0) return false;

        // Check if the single '1' bit is in an even position
        return (n & 0x55555555) != 0;
    }
};
