1class Solution {
2public:
3    string addBinary(string a, string b) {
4        string result = "";
5        int i = a.size() - 1;
6        int j = b.size() - 1;
7        int carry = 0;
8
9        while (i >= 0 || j >= 0 || carry) {
10            int sum = carry;
11
12            if (i >= 0) sum += a[i--] - '0';  // Convert char to int
13            if (j >= 0) sum += b[j--] - '0';
14
15            carry = sum / 2;
16            result += (sum % 2) + '0';  // Convert int to char
17        }
18
19        reverse(result.begin(), result.end());
20        return result;
21    }
22};
23