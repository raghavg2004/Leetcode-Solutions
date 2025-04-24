class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> totalDistinct(nums.begin(), nums.end());
        int total = totalDistinct.size();
        int result = 0;

        for (int i = 0; i < n; ++i) {
            unordered_set<int> seen;
            for (int j = i; j < n; ++j) {
                seen.insert(nums[j]);
                if (seen.size() == total) {
                    result++;
                }
            }
        }
        return result;
    }
};
