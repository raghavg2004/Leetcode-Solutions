class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> res;
        unordered_set<int> prev;

        for (int num : arr) {
            unordered_set<int> curr;
            curr.insert(num);

            for (int x : prev) {
                curr.insert(x | num);
            }

            for (int x : curr) {
                res.insert(x);
            }

            prev = curr;
        }

        return res.size();
    }
};
