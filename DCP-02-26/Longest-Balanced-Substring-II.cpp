1class Solution {
2public:
3    int longestBalanced(string s) {
4        int x = calc1(s);
5        int y = max({calc2(s, 'a', 'b'),
6                     calc2(s, 'b', 'c'),
7                     calc2(s, 'a', 'c')});
8        int z = calc3(s);
9        return max({x, y, z});
10    }
11
12private:
13    int calc1(const string& s) {
14        int res = 0;
15        for (int i = 0; i < s.size();) {
16            int j = i;
17            while (j < s.size() && s[j] == s[i]) j++;
18            res = max(res, j - i);
19            i = j;
20        }
21        return res;
22    }
23
24    int calc2(const string& s, char a, char b) {
25        int res = 0, n = s.size(), i = 0;
26        while (i < n) {
27            while (i < n && s[i] != a && s[i] != b) i++;
28            unordered_map<int,int> mp;
29            mp[0] = i - 1;
30            int diff = 0;
31            while (i < n && (s[i] == a || s[i] == b)) {
32                diff += (s[i] == a ? 1 : -1);
33                if (mp.count(diff))
34                    res = max(res, i - mp[diff]);
35                else
36                    mp[diff] = i;
37                i++;
38            }
39        }
40        return res;
41    }
42
43    long long key(int x, int y) {
44        return ((long long)(x + 100000) << 20) | (y + 100000);
45    }
46
47    int calc3(const string& s) {
48        unordered_map<long long,int> mp;
49        mp[key(0,0)] = -1;
50        int cnt[3] = {0};
51        int res = 0;
52        for (int i = 0; i < s.size(); i++) {
53            cnt[s[i] - 'a']++;
54            int x = cnt[0] - cnt[1];
55            int y = cnt[1] - cnt[2];
56            long long k = key(x,y);
57            if (mp.count(k))
58                res = max(res, i - mp[k]);
59            else
60                mp[k] = i;
61        }
62        return res;
63    }
64};