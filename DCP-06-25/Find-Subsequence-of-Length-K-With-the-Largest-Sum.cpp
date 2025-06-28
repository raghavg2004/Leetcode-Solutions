class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int, int>> indexed;

        // Step 1: Store value with original index
        for (int i = 0; i < n; ++i) {
            indexed.push_back({nums[i], i});
        }

        // Step 2: Sort in descending order of value
        sort(indexed.begin(), indexed.end(), [](auto& a, auto& b) {
            return a.first > b.first;
        });

        // Step 3: Take top k elements
        vector<pair<int, int>> topK(indexed.begin(), indexed.begin() + k);

        // Step 4: Sort top k by original index to preserve order
        sort(topK.begin(), topK.end(), [](auto& a, auto& b) {
            return a.second < b.second;
        });

        // Step 5: Extract values
        vector<int> result;
        for (auto& p : topK) {
            result.push_back(p.first);
        }

        return result;
    }
};
