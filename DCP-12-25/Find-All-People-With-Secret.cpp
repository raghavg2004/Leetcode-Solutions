1class Solution {
2public:
3    vector<int> findAllPeople(int n, vector<vector<int>>& meetings,
4                              int firstPerson) {
5        // Sort meetings in increasing order of time
6        sort(meetings.begin(), meetings.end(),
7             [](auto& a, auto& b) { return a[2] < b[2]; });
8
9        // Group Meetings in increasing order of time
10        map<int, vector<pair<int, int>>> sameTimeMeetings;
11        for (auto& meeting : meetings) {
12            int x = meeting[0], y = meeting[1], t = meeting[2];
13            sameTimeMeetings[t].emplace_back(x, y);
14        }
15
16        // Boolean Array to mark if a person knows the secret or not
17        vector<bool> knowsSecret(n, false);
18        knowsSecret[0] = true;
19        knowsSecret[firstPerson] = true;
20
21        // Process in increasing order of time
22        for (auto& [t, meetings] : sameTimeMeetings) {
23            // For each person, save all the people whom he/she meets at time t
24            unordered_map<int, vector<int>> meet;
25            for (auto& [x, y] : meetings) {
26                meet[x].push_back(y);
27                meet[y].push_back(x);
28            }
29
30            // Start traversal from those who already know the secret at time t
31            // Set to avoid redundancy
32            unordered_set<int> start;
33            for (auto& [x, y] : meetings) {
34                if (knowsSecret[x]) {
35                    start.insert(x);
36                }
37                if (knowsSecret[y]) {
38                    start.insert(y);
39                }
40            }
41
42            // Do BFS
43            queue<int> q;
44            for (auto& person : start) {
45                q.push(person);
46            }
47            while (!q.empty()) {
48                int person = q.front();
49                q.pop();
50                for (auto& nextPerson : meet[person]) {
51                    if (!knowsSecret[nextPerson]) {
52                        knowsSecret[nextPerson] = true;
53                        q.push(nextPerson);
54                    }
55                }
56            }
57        }
58
59        // List of people who know the secret
60        vector<int> ans;
61        for (int i = 0; i < n; ++i) {
62            if (knowsSecret[i]) {
63                ans.push_back(i);
64            }
65        }
66        return ans;
67    }
68};