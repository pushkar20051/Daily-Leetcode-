#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> map;
        // store key -> value
        for (auto &pair : knowledge) {
            map[pair[0]] = pair[1];
        }

        string res;
        int i = 0;
        while (i < s.size()) {
            if (s[i] == '(') {
                int j = i + 1;
                while (s[j] != ')') {
                    j++;
                }
                // Extract key
                string key = s.substr(i + 1, j - i - 1);
                // Get value or ?
                if (map.find(key) != map.end()) {
                    res += map[key];
                } else {
                    res += "?";
                }
                // Move after ')'
                i = j + 1;
            } else {
                res += s[i];
                i++;
            }
        }
        return res;
    }
};