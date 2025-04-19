#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> pos(n); // To store the position of each element in nums2
        for (int i = 0; i < n; ++i) {
            pos[nums2[i]] = i; // Map each value to its index in nums2
        }

        vector<int> nums; // Will store indices of nums1 in the order of their positions in nums2
        for (int i = 0; i < n; ++i) {
            nums.push_back(pos[nums1[i]]);
        }

        // Fenwick Tree for counting prefixes and suffixes
        auto update = [](vector<int>& bit, int index, int value) {
            while (index < bit.size()) {
                bit[index] += value;
                index += index & -index;
            }
        };

        auto query = [](vector<int>& bit, int index) {
            int sum = 0;
            while (index > 0) {
                sum += bit[index];
                index -= index & -index;
            }
            return sum;
        };

        // Step 1: Count prefix smaller elements
        vector<int> left(n); // left[i] = count of smaller elements before nums[i]
        vector<int> bit(n + 1, 0); // Fenwick Tree
        for (int i = 0; i < n; ++i) {
            left[i] = query(bit, nums[i]);
            update(bit, nums[i] + 1, 1);
        }

        // Step 2: Count suffix larger elements
        vector<int> right(n); // right[i] = count of larger elements after nums[i]
        fill(bit.begin(), bit.end(), 0); // Reset Fenwick Tree
        for (int i = n - 1; i >= 0; --i) {
            right[i] = query(bit, n) - query(bit, nums[i] + 1);
            update(bit, nums[i] + 1, 1);
        }

        // Step 3: Calculate good triplets
        long long result = 0;
        for (int i = 0; i < n; ++i) {
            result += 1LL * left[i] * right[i]; // Valid triplets contributed by nums[i]
        }

        return result;
    }
};