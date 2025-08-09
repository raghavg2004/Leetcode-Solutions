class Solution {
public:
    bool isPowerOfTwo(int n) {
        // must be positive and have only one bit set in binary
        return n > 0 && (n & (n - 1)) == 0;
    }
};
