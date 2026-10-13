class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> sqrt(n);
        long long score = 0;

        for (int i = 0; i < n; i++) {
            sqrt[i] = (long long) nums[i] * nums[i];
        }
        sort(sqrt.begin(), sqrt.end());
        for (int i = 0; i < n / 2; i++) {
            score -= sqrt[i];
        }

        for (int i = n / 2; i < n; i++) {
            score += sqrt[i];
        }
        return score;
    }
};