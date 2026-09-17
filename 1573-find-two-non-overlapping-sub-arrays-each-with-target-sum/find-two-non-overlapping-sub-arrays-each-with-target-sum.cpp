class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int start = 0;
        int end = 0;
        int n = arr.size();
        int minLen = INT_MAX;
        vector<int> best(n, INT_MAX);
        int sum = 0;
        int ans = INT_MAX;
        while (end < n) {
            sum += arr[end];
            end++;
            while (sum > target && start < end) {
                sum -= arr[start];
                start++;
            }
            if (sum == target) {
                int curLen = end - start;
                minLen = min(minLen, curLen);
                if (start > 0 && best[start - 1] != INT_MAX) {
                    ans = min(ans, curLen + best[start - 1]);
                }
            }
            best[end - 1] = minLen;
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};