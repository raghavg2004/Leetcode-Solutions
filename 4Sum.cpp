class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int n = nums.size();

        // Step 1: Sort the array to simplify duplicate handling and enable two-pointer technique
        sort(nums.begin(), nums.end());

        // Step 2: Fix the first element of the quadruplet
        for (int i = 0; i < n - 3; ++i) {
            // Skip duplicates for the first element
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            // Step 3: Fix the second element of the quadruplet
            for (int j = i + 1; j < n - 2; ++j) {
                // Skip duplicates for the second element
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                // Step 4: Use two pointers to find the remaining two elements
                long long newTarget = (long long)target - nums[i] - nums[j]; // Avoid integer overflow
                int left = j + 1;
                int right = n - 1;

                while (left < right) {
                    long long sum = nums[left] + nums[right]; // Avoid overflow

                    if (sum == newTarget) {
                        // Found a valid quadruplet
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});

                        // Skip duplicate values for the third element
                        while (left < right && nums[left] == nums[left + 1]) ++left;

                        // Skip duplicate values for the fourth element
                        while (left < right && nums[right] == nums[right - 1]) --right;

                        // Move both pointers after processing current pair
                        ++left;
                        --right;
                    } else if (sum < newTarget) {
                        ++left; // Need a larger sum
                    } else {
                        --right; // Need a smaller sum
                    }
                }
            }
        }

        return result; // Return all unique quadruplets
    }
};
