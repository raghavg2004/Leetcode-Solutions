1class Solution {
2public:
3    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
4        int n = code.size();
5
6        // Mapping from business line name to its required sort order
7        unordered_map<string, int> businessLineSortOrder = {
8            {"electronics", 0},
9            {"grocery", 1},
10            {"pharmacy", 2},
11            {"restaurant", 3}
12        };
13
14        // Store each valid coupon with the information needed for sorting
15        // First field: (business line order, code), Second field: code string
16        vector<pair<pair<int, string>, string>> sortableCoupons;
17
18        for (int i = 0; i < n; ++i) {
19            // Check coupon is currently active
20            if (!isActive[i]) continue;
21
22            // Check if business line is valid
23            if (businessLineSortOrder.find(businessLine[i]) == businessLineSortOrder.end()) continue;
24
25            // Check if code is non-empty and only alphanumeric or underscore
26            if (code[i].empty()) continue; //""
27            bool isCodeValid = true;
28            for (char c : code[i]) {
29                if (!(isalnum(c) || c == '_')) {
30                    isCodeValid = false;
31                    break;
32                }
33            }
34            if (!isCodeValid) continue;
35
36            // Everything is valid, collect coupon for sorting
37            int sortIndex = businessLineSortOrder[businessLine[i]];
38            sortableCoupons.push_back({{sortIndex, code[i]}, code[i]});
39        }
40
41        // Sort by business line order, then code alphabetically
42        sort(sortableCoupons.begin(), sortableCoupons.end());
43
44        // Gather the sorted coupon codes
45        vector<string> sortedValidCodes;
46        for (auto& entry : sortableCoupons) {
47            sortedValidCodes.push_back(entry.second);
48        }
49
50        return sortedValidCodes;
51    }
52};