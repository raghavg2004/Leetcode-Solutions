class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);

        // Get max value by changing first non-9 digit to 9
        string maxS = s;
        for (char c : s) {
            if (c != '9') {
                char from = c;
                for (char &ch : maxS) {
                    if (ch == from) ch = '9';
                }
                break;
            }
        }

        // Get min value by changing first non-0 digit to 0
        string minS = s;
        for (char c : s) {
            if (c != '0') {
                char from = c;
                for (char &ch : minS) {
                    if (ch == from) ch = '0';
                }
                break;
            }
        }

        int maxVal = stoi(maxS);
        int minVal = stoi(minS);

        return maxVal - minVal;
    }
};
