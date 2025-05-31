class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<bool> visited(n * n + 1, false);
        queue<pair<int, int>> q; // (position, steps)
        q.push({1, 0});
        visited[1] = true;

        while (!q.empty()) {
            auto [curr, steps] = q.front();
            q.pop();
            
            for (int move = 1; move <= 6; ++move) {
                int next = curr + move;
                if (next > n * n) break;

                auto [r, c] = getCoordinates(next, n);
                if (board[r][c] != -1)
                    next = board[r][c];

                if (next == n * n) return steps + 1;

                if (!visited[next]) {
                    visited[next] = true;
                    q.push({next, steps + 1});
                }
            }
        }

        return -1;
    }

private:
    pair<int, int> getCoordinates(int label, int n) {
        int row = (label - 1) / n;
        int col = (label - 1) % n;
        int realRow = n - 1 - row;
        int realCol = row % 2 == 0 ? col : n - 1 - col;
        return {realRow, realCol};
    }
};
