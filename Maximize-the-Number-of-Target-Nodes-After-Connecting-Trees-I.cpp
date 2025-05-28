class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;
        
        vector<vector<int>> tree1(n), tree2(m);
        
        for (auto& e : edges1) {
            tree1[e[0]].push_back(e[1]);
            tree1[e[1]].push_back(e[0]);
        }
        
        for (auto& e : edges2) {
            tree2[e[0]].push_back(e[1]);
            tree2[e[1]].push_back(e[0]);
        }
        
        // Precompute Tree2: number of nodes within distance d from each node
        vector<int> countFromTree2(m);
        for (int i = 0; i < m; ++i) {
            countFromTree2[i] = bfsWithinDistance(tree2, i, k - 1);
        }
        
        vector<int> result(n);
        
        for (int i = 0; i < n; ++i) {
            int localTree1Count = bfsWithinDistance(tree1, i, k);
            int maxCount = 0;
            for (int j = 0; j < m; ++j) {
                int count = localTree1Count + countFromTree2[j];
                maxCount = max(maxCount, count);
            }
            result[i] = maxCount;
        }
        
        return result;
    }

private:
    int bfsWithinDistance(vector<vector<int>>& tree, int start, int maxDist) {
        int count = 0;
        int n = tree.size();
        vector<bool> visited(n, false);
        queue<pair<int, int>> q;
        q.push({start, 0});
        visited[start] = true;

        while (!q.empty()) {
            auto [node, dist] = q.front(); q.pop();
            if (dist > maxDist) continue;
            count++;
            for (int neighbor : tree[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push({neighbor, dist + 1});
                }
            }
        }
        return count;
    }
};
