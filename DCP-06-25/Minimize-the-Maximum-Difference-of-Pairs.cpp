class Solution {
public:
    bool canFormPairs(vector<int>& nums, int p, int maxDiff) {
        int count = 0;
        for (int i = 1; i < nums.size(); ) {
            if (nums[i] - nums[i - 1] <= maxDiff) {
                count++;
                i += 2;  // use both elements in this pair
            } else {
                i += 1;  // skip one element
            }
        }
        return count >= p;
    }

    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.back() - nums.front();
        int answer = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canFormPairs(nums, p, mid)) {
                answer = mid;
                right = mid - 1;  // try to find a smaller max difference
            } else {
                left = mid + 1;   // need to allow more difference
            }
        }

        return answer;
    }
};
