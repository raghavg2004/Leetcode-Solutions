class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size(); i += 3) {
            int min_val = nums[i];
            int max_val = nums[i + 2]; // nums[i], nums[i+1], nums[i+2] are sorted
            if (max_val - min_val > k) {
                return {};
            }
            result.push_back({nums[i], nums[i + 1], nums[i + 2]});
        }

        return result;
    }
};
