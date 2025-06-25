class Solution {
public:
    long long countLessEqual(const vector<int>& nums1, const vector<int>& nums2, long long x) {
        long long count = 0;
        int n2 = nums2.size();

        for (int a : nums1) {
            if (a == 0) {
                if (x >= 0) count += n2;
                // else count += 0
            } else if (a > 0) {
                // Find max j such that a * nums2[j] <= x
                int l = 0, r = n2 - 1;
                while (l <= r) {
                    int m = l + (r - l) / 2;
                    if ((long long)a * nums2[m] <= x) l = m + 1;
                    else r = m - 1;
                }
                count += l;
            } else { // a < 0
                // Find min j such that a * nums2[j] <= x
                int l = 0, r = n2 - 1;
                while (l <= r) {
                    int m = l + (r - l) / 2;
                    if ((long long)a * nums2[m] <= x) r = m - 1;
                    else l = m + 1;
                }
                count += n2 - l;
            }
        }
        return count;
    }

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        long long left = -1e10, right = 1e10;

        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (countLessEqual(nums1, nums2, mid) < k)
                left = mid + 1;
            else
                right = mid;
        }

        return left;
    }
};
