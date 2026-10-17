class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int count = 0;
        unordered_set<int> s(nums.begin(), nums.end());
        for (int num : nums) {
            if (s.count(num + diff) && s.count(num + 2 * diff)) {
                count++;
            }
        }
        return count;
    }
};