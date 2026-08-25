class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> set;

        for (int i = 0; i < n; i++) {
            set.insert(nums[i]);
        }

        int multiple = k;

        while (true) {
            if (set.find(multiple) == set.end())
                return multiple;

            multiple += k;
        }
    }
};