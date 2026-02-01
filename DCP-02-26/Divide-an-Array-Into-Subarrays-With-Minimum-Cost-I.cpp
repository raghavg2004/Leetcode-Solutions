1class Solution {
2public:
3    int minimumCost(vector<int>& nums) {
4        int min1 = 100; 
5        int min2 = 100;
6        for(int i = 1; i < nums.size(); i++){
7            if(nums[i] < min1){
8                min2 = min1;
9                min1 = nums[i];
10            }
11            else if(nums[i] < min2){
12                min2 = nums[i];
13            }
14        }
15        return nums[0] + min1 + min2;
16    }
17};