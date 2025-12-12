1class Solution {
2public:
3    vector<int> countMentions(int numberOfUsers,
4                              vector<vector<string>>& events) {
5        vector<int> count(numberOfUsers);
6        vector<int> next_online_time(numberOfUsers);
7        sort(events.begin(), events.end(),
8             [&](const vector<string>& lth, const vector<string>& rth) {
9                 int lth_timestamp = stoi(lth[1]);
10                 int rth_timestamp = stoi(rth[1]);
11                 if (lth_timestamp != rth_timestamp) {
12                     return lth_timestamp < rth_timestamp;
13                 }
14                 if (rth[0] == "OFFLINE") {
15                     return false;
16                 }
17                 return true;
18             });
19
20        for (auto&& event : events) {
21            int cur_time = stoi(event[1]);
22            if (event[0] == "MESSAGE") {
23                if (event[2] == "ALL") {
24                    for (int i = 0; i < numberOfUsers; i++) {
25                        count[i]++;
26                    }
27                } else if (event[2] == "HERE") {
28                    for (int i = 0; i < numberOfUsers; i++) {
29                        if (next_online_time[i] <= cur_time) {
30                            count[i]++;
31                        }
32                    }
33                } else {
34                    int idx = 0;
35                    for (int i = 0; i < event[2].size(); i++) {
36                        if (isdigit(event[2][i])) {
37                            idx = idx * 10 + (event[2][i] - '0');
38                        }
39                        if (i + 1 == event[2].size() ||
40                            event[2][i + 1] == ' ') {
41                            count[idx]++;
42                            idx = 0;
43                        }
44                    }
45                }
46            } else {
47                int idx = stoi(event[2]);
48                next_online_time[idx] = cur_time + 60;
49            }
50        }
51        return count;
52    }
53};