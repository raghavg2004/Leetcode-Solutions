1class Solution {
2public:
3    long long minimumCost(string source, string target, vector<char>& original,
4                          vector<char>& changed, vector<int>& cost) {
5        // Create a graph representation of character conversions
6        vector<vector<pair<int, int>>> adjacencyList(26);
7
8        // Populate the adjacency list with character conversions
9        int conversionCount = original.size();
10        for (int i = 0; i < conversionCount; i++) {
11            adjacencyList[original[i] - 'a'].push_back(
12                {changed[i] - 'a', cost[i]});
13        }
14
15        // Calculate shortest paths for all possible character conversions
16        vector<vector<long long>> minConversionCosts(26, vector<long long>(26));
17        for (int i = 0; i < 26; i++) {
18            minConversionCosts[i] = dijkstra(i, adjacencyList);
19        }
20
21        // Calculate the total cost of converting source to target
22        long long totalCost = 0;
23        int stringLength = source.length();
24        for (int i = 0; i < stringLength; i++) {
25            if (source[i] != target[i]) {
26                long long charConversionCost =
27                    minConversionCosts[source[i] - 'a'][target[i] - 'a'];
28                if (charConversionCost == -1) {
29                    return -1;  // Conversion not possible
30                }
31                totalCost += charConversionCost;
32            }
33        }
34        return totalCost;
35    }
36
37private:
38    // Find minimum conversion costs from a starting character to all other
39    // characters
40    vector<long long> dijkstra(
41        int startChar, const vector<vector<pair<int, int>>>& adjacencyList) {
42        // Priority queue to store characters with their conversion cost, sorted
43        // by cost
44        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
45                       greater<pair<long long, int>>>
46            priorityQueue;
47
48        // Initialize the starting character with cost 0
49        priorityQueue.push({0, startChar});
50
51        // Array to store the minimum conversion cost to each character
52        vector<long long> minCosts(26, -1);
53
54        while (!priorityQueue.empty()) {
55            auto [currentCost, currentChar] = priorityQueue.top();
56            priorityQueue.pop();
57
58            if (minCosts[currentChar] != -1 &&
59                minCosts[currentChar] < currentCost)
60                continue;
61
62            // Explore all possible conversions from the current character
63            for (auto& [targetChar, conversionCost] :
64                 adjacencyList[currentChar]) {
65                long long newTotalCost = currentCost + conversionCost;
66
67                // If we found a cheaper conversion, update its cost
68                if (minCosts[targetChar] == -1 ||
69                    newTotalCost < minCosts[targetChar]) {
70                    minCosts[targetChar] = newTotalCost;
71                    // Add the updated conversion to the queue for further
72                    // exploration
73                    priorityQueue.push({newTotalCost, targetChar});
74                }
75            }
76        }
77        // Return the array of minimum conversion costs from the starting
78        // character to all others
79        return minCosts;
80    }
81};