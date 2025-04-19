class Solution {
public:
    string intToRoman(int num) {
        // A list of Roman numeral values and their corresponding symbols,
        // ordered from highest to lowest to allow greedy subtraction.
        vector<pair<int, string>> roman = {
            {1000, \M\}, {900, \CM\},
            {500, \D\}, {400, \CD\},
            {100, \C\}, {90, \XC\},
            {50, \L\}, {40, \XL\},
            {10, \X\}, {9, \IX\},
            {5, \V\}, {4, \IV\},
            {1, \I\}
        };

        string result; // To store the resulting Roman numeral

        // Iterate through each (value, symbol) pair in the Roman mapping
        for (const auto& [value, symbol] : roman) {
            // While the current number is greater than or equal to the Roman value,
            // subtract the value and append the symbol to the result.
            while (num >= value) {
                result += symbol; // Add symbol to result
                num -= value;     // Subtract value from number
            }
        }

        return result; // Return the final Roman numeral string
    }
};
