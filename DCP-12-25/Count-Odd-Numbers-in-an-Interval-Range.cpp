1class Solution {
2public:
3    int countOdds(int low, int high) {
4        return (high + 1) / 2 - (low / 2);
5    }
6};