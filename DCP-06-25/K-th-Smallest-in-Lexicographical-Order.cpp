class Solution {
public:
    int findKthNumber(int n, int k) {
        long prefix = 1;
        k = k - 1;  // we already consider 1 as the first number

        while (k > 0) {
            long steps = calcSteps(n, prefix);
            if (steps <= k) {
                k -= steps;
                prefix += 1;
            } else {
                prefix *= 10;
                k -= 1;
            }
        }
        return prefix;
    }

    long calcSteps(int n, long prefix) {
        long steps = 0;
        long first = prefix;
        long last = prefix;

        while (first <= n) {
            steps += min((long)n + 1, last + 1) - first;
            first *= 10;
            last = last * 10 + 9;
        }

        return steps;
    }
};
