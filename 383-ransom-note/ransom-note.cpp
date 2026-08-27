class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> map1;
        for (char ch : magazine) map1[ch]++;
        for (char ch : ransomNote) {
            if (map1[ch] == 0) return false;
            map1[ch]--;
        }
        return true;
    }
};