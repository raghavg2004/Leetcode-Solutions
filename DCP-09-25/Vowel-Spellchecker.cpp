#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exactSet(wordlist.begin(), wordlist.end());
        unordered_map<string, string> caseMap;
        unordered_map<string, string> vowelMap;

        // build maps
        for (string &word : wordlist) {
            string lower = toLower(word);
            string dev = devowel(lower);

            if (!caseMap.count(lower)) caseMap[lower] = word;
            if (!vowelMap.count(dev)) vowelMap[dev] = word;
        }

        vector<string> ans;
        for (string &q : queries) {
            if (exactSet.count(q)) {
                ans.push_back(q);
                continue;
            }
            string lower = toLower(q);
            if (caseMap.count(lower)) {
                ans.push_back(caseMap[lower]);
                continue;
            }
            string dev = devowel(lower);
            if (vowelMap.count(dev)) {
                ans.push_back(vowelMap[dev]);
                continue;
            }
            ans.push_back("");
        }
        return ans;
    }

private:
    string toLower(const string &s) {
        string res = s;
        for (char &c : res) c = tolower(c);
        return res;
    }

    string devowel(const string &s) {
        string res = s;
        for (char &c : res) {
            if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
                c = '*';
        }
        return res;
    }
};
