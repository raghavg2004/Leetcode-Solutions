class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> result;
        vector<int> count(10, 0);
        
        // Count each digit in the input
        for (int d : digits)
            count[d]++;
        
        // Iterate all 3-digit even numbers
        for (int num = 100; num <= 998; num += 2) {
            int a = num / 100;             // Hundreds digit
            int b = (num / 10) % 10;       // Tens digit
            int c = num % 10;              // Units digit

            vector<int> tempCount = count;

            // Check if digits are available
            if (--tempCount[a] >= 0 && --tempCount[b] >= 0 && --tempCount[c] >= 0) {
                result.push_back(num);
            }
        }

        return result;
    }
};
