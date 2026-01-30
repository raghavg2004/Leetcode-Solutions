1struct Trie {
2    Trie* child[26];
3    int id;
4
5    Trie() {
6        for (int i = 0; i < 26; ++i) {
7            child[i] = nullptr;
8        }
9        id = -1;
10    }
11};
12
13int add(Trie* node, const string& word, int& index) {
14    for (char ch : word) {
15        int i = ch - 'a';
16        if (!node->child[i]) {
17            node->child[i] = new Trie();
18        }
19        node = node->child[i];
20    }
21    if (node->id == -1) {
22        node->id = ++index;
23    }
24    return node->id;
25}
26
27void update(long long& x, long long y) {
28    if (x == -1 || y < x) {
29        x = y;
30    }
31}
32
33class Solution {
34public:
35    long long minimumCost(string source, string target,
36                          vector<string>& original, vector<string>& changed,
37                          vector<int>& cost) {
38        int n = source.size();
39        int m = original.size();
40        Trie* root = new Trie();
41
42        int p = -1;
43        vector<vector<int>> G(m * 2, vector<int>(m * 2, inf));
44        for (int i = 0; i < m * 2; ++i) {
45            G[i][i] = 0;
46        }
47        for (int i = 0; i < m; ++i) {
48            int x = add(root, original[i], p);
49            int y = add(root, changed[i], p);
50            G[x][y] = min(G[x][y], cost[i]);
51        }
52
53        for (int k = 0; k <= p; ++k) {
54            for (int i = 0; i <= p; ++i) {
55                for (int j = 0; j <= p; ++j) {
56                    G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
57                }
58            }
59        }
60
61        vector<long long> f(n, -1);
62        for (int j = 0; j < n; ++j) {
63            if (j > 0 && f[j - 1] == -1) {
64                continue;
65            }
66            long long base = (j == 0 ? 0 : f[j - 1]);
67            if (source[j] == target[j]) {
68                update(f[j], base);
69            }
70            Trie* u = root;
71            Trie* v = root;
72            for (int i = j; i < n; ++i) {
73                u = u->child[source[i] - 'a'];
74                v = v->child[target[i] - 'a'];
75                if (!u || !v) {
76                    break;
77                }
78                if (u->id != -1 && v->id != -1 && G[u->id][v->id] != inf) {
79                    update(f[i], base + G[u->id][v->id]);
80                }
81            }
82        }
83        return f[n - 1];
84    }
85
86private:
87    static constexpr int inf = INT_MAX / 2;
88};