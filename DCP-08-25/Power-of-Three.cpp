class Solution {
public:
    bool isPowerOfThree(int n) {
        // Max power of 3 within 32-bit signed int
        const int MAX_POWER_OF_THREE = 1162261467; // 3^19
        return n > 0 && (MAX_POWER_OF_THREE % n == 0);
    }
};
