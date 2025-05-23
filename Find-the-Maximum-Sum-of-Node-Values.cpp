class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long total = 0;
        int countPositive = 0;
        int minDiff = INT_MAX;

        for (int num : nums) {
            int x = num ^ k;
            int diff = x - num;

            if (diff > 0) {
                total += x;
                countPositive++;
            } else {
                total += num;
            }
            // Keep track of the smallest absolute loss if count is odd
            minDiff = min(minDiff, abs(diff));
        }

        // If count of positive diffs is odd, we need to revert one XOR
        if (countPositive % 2 != 0) {
            total -= minDiff;
        }

        return total;
    }
};
