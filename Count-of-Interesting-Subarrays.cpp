class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        unordered_map<int, long long> count;
        count[0] = 1;  // initial prefix sum modulo is 0
        long long res = 0;
        int prefix = 0;

        for (int num : nums) {
            if (num % modulo == k)
                prefix = (prefix + 1) % modulo;
            else
                prefix = prefix % modulo;

            // We want (prefix - k + modulo) % modulo
            int target = (prefix - k + modulo) % modulo;
            if (count.count(target)) {
                res += count[target];
            }

            count[prefix]++;
        }

        return res;
    }
};
