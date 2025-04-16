class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long ans = 0, pairs = 0;
        unordered_map<int, int> freq;
        int left = 0;

        for (int right = 0; right < nums.size(); ++right) {
            pairs += freq[nums[right]];
            freq[nums[right]]++;

            while (pairs >= k) {
                ans += nums.size() - right;
                freq[nums[left]]--;
                pairs -= freq[nums[left]];
                left++;
            }
        }

        return ans;
    }
};
