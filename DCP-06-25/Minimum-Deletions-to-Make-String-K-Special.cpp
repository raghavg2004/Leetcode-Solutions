class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char, int> freq;
        for (char c : word)
            freq[c]++;

        vector<int> freqList;
        for (auto& [ch, count] : freq)
            freqList.push_back(count);

        sort(freqList.begin(), freqList.end());
        int n = freqList.size();
        int minDel = INT_MAX;

        for (int i = 0; i < n; ++i) {
            int targetMin = freqList[i];
            int targetMax = targetMin + k;
            int deletions = 0;

            for (int j = 0; j < n; ++j) {
                if (freqList[j] < targetMin) {
                    // freq is already less than targetMin, delete all
                    deletions += freqList[j];
                } else if (freqList[j] > targetMax) {
                    // freq is above allowed max, reduce to targetMax
                    deletions += freqList[j] - targetMax;
                }
                // else in range [targetMin, targetMax] → do nothing
            }
            minDel = min(minDel, deletions);
        }

        return minDel;
    }
};
