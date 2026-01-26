1class Solution {
2public:
3    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
4        sort(arr.begin(), arr.end());
5        vector<vector<int>> result;
6        int min_diff = INT_MAX;
7        
8        for (size_t i = 0; i < arr.size() - 1; ++i) {
9            int current_diff = arr[i+1] - arr[i];
10            if (current_diff < min_diff) {
11                min_diff = current_diff;
12                result.clear();
13                result.push_back({arr[i], arr[i+1]});
14            } else if (current_diff == min_diff) {
15                result.push_back({arr[i], arr[i+1]});
16            }
17        }
18        return result;
19    }
20};