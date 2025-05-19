class Solution {
public:
    string triangleType(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        // Check triangle inequality
        if (nums[0] + nums[1] <= nums[2]) {
            return "none";
        }
        
        // All sides equal
        if (nums[0] == nums[1] && nums[1] == nums[2]) {
            return "equilateral";
        }
        
        // Two sides equal
        if (nums[0] == nums[1] || nums[1] == nums[2] || nums[0] == nums[2]) {
            return "isosceles";
        }
        
        // All sides different
        return "scalene";
    }
};
