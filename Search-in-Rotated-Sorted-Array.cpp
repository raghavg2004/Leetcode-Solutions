class Solution {
public:
    int search(vector<int>& nums, int target) {
         int n = nums.size();
        
        // Step 1: Find the pivot (smallest element index)
        int start = 0, end = n - 1;
        while (start < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] > nums[end]) {
                start = mid + 1; // Pivot is in the right half
            } else {
                end = mid; // Pivot is in the left half
            }
        }
        
        int pivot = start; // The index of the smallest element
        start = 0, end = n - 1;
        
        // Step 2: Determine which part of the array to search in
        if (target >= nums[pivot] && target <= nums[end]) {
            start = pivot; // Search in the right part
        } else {
            end = pivot - 1; // Search in the left part
        }
        
        // Step 3: Perform binary search in the determined range
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                return mid; // Target found
            } else if (nums[mid] < target) {
                start = mid + 1; // Move to the right
            } else {
                end = mid - 1; // Move to the left
            }
        }
        return -1; // Target not found
    }
};