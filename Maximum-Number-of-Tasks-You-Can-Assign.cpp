class Solution {
public:
    bool canAssign(int k, vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        multiset<int> availableWorkers(workers.end() - k, workers.end());

        for (int i = k - 1; i >= 0; --i) { // from hardest task to easiest
            int task = tasks[i];
            
            // Try without pill: assign to the strongest available worker
            auto it = prev(availableWorkers.end());
            if (*it >= task) {
                availableWorkers.erase(it);
                continue;
            }

            // Try with pill: find the weakest worker who with pill can do the task
            it = availableWorkers.lower_bound(task - strength);
            if (it == availableWorkers.end() || pills == 0) {
                return false; // no one can do it even with pill
            }

            availableWorkers.erase(it);
            --pills;
        }

        return true;
    }

    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        int left = 0, right = min(tasks.size(), workers.size());
        int answer = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canAssign(mid, tasks, workers, pills, strength)) {
                answer = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return answer;
    }
};