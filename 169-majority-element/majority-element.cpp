class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> map;
        for (int num : nums) {
            map[num]++;
        }
        for (auto entry : map) {
            if (entry.second > n / 2) {
                return entry.first;
            }
        }
        return -1;
    }
};