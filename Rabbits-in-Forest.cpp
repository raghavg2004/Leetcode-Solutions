class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> count;
        int res = 0;

        // Count frequency of each answer
        for (int a : answers) {
            count[a]++;
        }

        for (auto [x, freq] : count) {
            int groupSize = x + 1;

            // Number of groups needed (ceil division)
            int groups = (freq + groupSize - 1) / groupSize;

            // Total rabbits in these groups
            res += groups * groupSize;
        }

        return res;
    }
};
