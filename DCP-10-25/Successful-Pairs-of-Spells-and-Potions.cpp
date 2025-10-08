class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = potions.size(), m = spells.size();
        vector<int> ret(m);
        sort(potions.begin(), potions.end());
        for (int r = 0; r < m; ++r) {
            long long s = spells[r];
            long long temp = (success + s - 1) / s;
            auto it = lower_bound(potions.begin(), potions.end(), temp);
            ret[r] = n - static_cast<int>(it - potions.begin());
        }
        return ret;
    }
};