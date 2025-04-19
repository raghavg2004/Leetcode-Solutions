class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long count = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            int left = lower - nums[i];
            int right = upper - nums[i];

            // Use lower_bound to find the first index >= left
            auto it1 = lower_bound(nums.begin() + i + 1, nums.end(), left);
            // Use upper_bound to find the first index > right
            auto it2 = upper_bound(nums.begin() + i + 1, nums.end(), right);
            
            count += it2 - it1;
        }

        return count;
    }
};
