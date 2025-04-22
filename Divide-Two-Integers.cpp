class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle overflow case: INT_MIN / -1 => overflow
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        // Convert to long long to handle INT_MIN safely
        long long a = dividend;
        long long b = divisor;

        // Work with absolute values
        bool negative = (a < 0) ^ (b < 0);  // XOR for different signs
        a = llabs(a);
        b = llabs(b);

        long long result = 0;

        while (a >= b) {
            long long temp = b, multiple = 1;
            while (a >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            a -= temp;
            result += multiple;
        }

        result = negative ? -result : result;

        // Clamp to int range
        if (result > INT_MAX) return INT_MAX;
        if (result < INT_MIN) return INT_MIN;
        return (int)result;
    }
};
