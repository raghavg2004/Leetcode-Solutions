class Solution {
public:
    int pivotIndex(vector<int>& nums) {
    int totalSum = 0;  // To store the sum of all elements
        for (int num : nums) {
            totalSum += num;
        }
        
        int leftSum = 0;  // Initialize leftSum to 0
        for (int i = 0; i < nums.size(); ++i) {
            // Right sum is totalSum - leftSum - nums[i] (current element)
            if (leftSum == totalSum - leftSum - nums[i]) {
                return i;  // Pivot index found
            }
            leftSum += nums[i];  // Update leftSum
        }
        
        return -1;  // No pivot index found
    }
};