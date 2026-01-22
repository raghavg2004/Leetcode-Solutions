1class Solution {
2public:
3    int minimumPairRemoval(std::vector<int>& nums) {
4        int count = 0;
5
6        while (nums.size() > 1) {
7            bool isAscending = true;
8            int minSum = std::numeric_limits<int>::max();
9            int targetIndex = -1;
10
11            for (size_t i = 0; i < nums.size() - 1; ++i) {
12                int sum = nums[i] + nums[i + 1];
13
14                if (nums[i] > nums[i + 1]) {
15                    isAscending = false;
16                }
17
18                if (sum < minSum) {
19                    minSum = sum;
20                    targetIndex = static_cast<int>(i);
21                }
22            }
23
24            if (isAscending) {
25                break;
26            }
27
28            count++;
29            nums[targetIndex] = minSum;
30            nums.erase(nums.begin() + targetIndex + 1);
31        }
32
33        return count;
34    }
35};