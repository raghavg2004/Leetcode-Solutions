1class Solution {
2public:
3    char nextGreatestLetter(vector<char>& letters, char target) {
4        char res = letters[0];
5        bool flag = false;
6
7        for (char ch : letters) {
8            if (!flag) {
9                if (ch > target) {
10                    res = ch;
11                    flag = !flag;
12                }
13            } else {
14                if (ch > target && ch < res) res = ch;
15            }
16        }
17
18        return res;
19    }
20};