class Solution {
public:
    int countLargestGroup(int n) {
        vector<int> count(37, 0); // 0-36 possible digit sums

        for (int i = 1; i <= n; i++) {
            int sum = digitSum(i);
            count[sum]++;
        }

        int maxSize = *max_element(count.begin(), count.end());
        int groups = 0;
        for (int c : count) {
            if (c == maxSize)
                groups++;
        }

        return groups;
    }

private:
    int digitSum(int num) {
        int sum = 0;
        while (num) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
};
