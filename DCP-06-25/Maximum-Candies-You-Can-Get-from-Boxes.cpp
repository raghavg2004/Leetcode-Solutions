class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, 
                   vector<vector<int>>& keys, 
                   vector<vector<int>>& containedBoxes, 
                   vector<int>& initialBoxes) {

        int n = status.size();
        vector<bool> hasBox(n, false);
        vector<bool> hasKey(n, false);
        vector<bool> visited(n, false);

        queue<int> q;

        for (int box : initialBoxes) {
            hasBox[box] = true;
        }

        bool progress = true;
        int totalCandies = 0;

        while (progress) {
            progress = false;
            for (int i = 0; i < n; ++i) {
                if (hasBox[i] && (status[i] == 1 || hasKey[i]) && !visited[i]) {
                    // Open the box
                    visited[i] = true;
                    totalCandies += candies[i];
                    progress = true;

                    // Collect keys
                    for (int k : keys[i]) {
                        if (!hasKey[k]) {
                            hasKey[k] = true;
                        }
                    }

                    // Collect contained boxes
                    for (int b : containedBoxes[i]) {
                        if (!hasBox[b]) {
                            hasBox[b] = true;
                        }
                    }

                    // If box was closed but we have key, mark it open
                    if (status[i] == 0 && hasKey[i]) {
                        status[i] = 1;
                    }
                }
            }
        }

        return totalCandies;
    }
};
