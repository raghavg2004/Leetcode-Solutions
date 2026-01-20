1class Solution {
2public:
3    vector<int> minBitwiseArray(vector<int>& nums) {
4        for (int i = 0; i < nums.size(); i++) {
5            int tmp = nums[i];
6            for (int j = 1; j < nums[i]; j++) {
7                if ((j | (j + 1)) == nums[i]) {
8                    nums[i] = j;
9                    break;
10                }
11            }
12            if (nums[i] == tmp) {
13                nums[i] = -1;
14            }
15        }
16        return nums;
17    }
18};