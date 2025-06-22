#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> result;
        int n = s.length();
        
        for (int i = 0; i < n; i += k) {
            string group = s.substr(i, k);
            if (group.length() < k) {
                group.append(k - group.length(), fill); // fill with `fill` character
            }
            result.push_back(group);
        }
        
        return result;
    }
};
