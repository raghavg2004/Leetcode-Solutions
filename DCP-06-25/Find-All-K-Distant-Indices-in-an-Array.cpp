class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int> result;
        vector<bool> isKDistant(n, false);

        // Step 1: Find all indices where nums[j] == key
        for (int j = 0; j < n; ++j) {
            if (nums[j] == key) {
                // Step 2: Mark indices i in range [j - k, j + k]
                int start = max(0, j - k);
                int end = min(n - 1, j + k);
                for (int i = start; i <= end; ++i) {
                    isKDistant[i] = true;
                }
            }
        }

        // Step 3: Collect all marked indices
        for (int i = 0; i < n; ++i) {
            if (isKDistant[i]) {
                result.push_back(i);
            }
        }

        return result;
    }
};
