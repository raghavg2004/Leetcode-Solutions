class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);

        // Build graph and indegree count
        for (auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }

        // dp[node][color] stores max frequency of a color up to this node
        vector<vector<int>> dp(n, vector<int>(26, 0));
        queue<int> q;

        // Start with nodes having 0 indegree
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0)
                q.push(i);
        }

        int visited = 0;
        int result = 0;

        while (!q.empty()) {
            int node = q.front(); q.pop();
            visited++;

            // Update current node's color count
            dp[node][colors[node] - 'a']++;

            // Update neighbors
            for (int nei : graph[node]) {
                for (int c = 0; c < 26; ++c) {
                    dp[nei][c] = max(dp[nei][c], dp[node][c]);
                }
                if (--indegree[nei] == 0)
                    q.push(nei);
            }

            // Update result with the maximum value at current node
            result = max(result, *max_element(dp[node].begin(), dp[node].end()));
        }

        return visited == n ? result : -1;  // If cycle, return -1
    }
};
