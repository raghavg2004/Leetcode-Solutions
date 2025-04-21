class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long prefix_sum = 0;
        long long min_prefix = 0;
        long long max_prefix = 0;
        
        for (int diff : differences) {
            prefix_sum += diff;
            min_prefix = min(min_prefix, prefix_sum);
            max_prefix = max(max_prefix, prefix_sum);
        }

        long long low = lower - min_prefix;
        long long high = upper - max_prefix;

        return max(0LL, high - low + 1);
    }
};
