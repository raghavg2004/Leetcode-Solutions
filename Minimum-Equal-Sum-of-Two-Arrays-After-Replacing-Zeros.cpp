class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long s1 = 0, s2 = 0;
        int z1 = 0, z2 = 0;

        for (int num : nums1) {
            if (num == 0) z1++;
            else s1 += num;
        }
        for (int num : nums2) {
            if (num == 0) z2++;
            else s2 += num;
        }

        // If both have no zeros and sums differ
        if (z1 == 0 && z2 == 0 && s1 != s2) return -1;

        long long min1 = s1 + z1;
        long long min2 = s2 + z2;

        if (min1 > min2 && z2 == 0) return -1;
        if (min2 > min1 && z1 == 0) return -1;

        return max(min1, min2);
    }
};