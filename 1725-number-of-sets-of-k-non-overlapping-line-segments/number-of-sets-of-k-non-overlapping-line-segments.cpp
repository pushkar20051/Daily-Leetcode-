class Solution {
public:
    static const int MOD = 1'000'000'007;

    int numberOfSets(int n, int k) {

        // dp[n][k]
        vector<vector<long long>> dp(n, vector<long long>(k + 1, 0));

        // prefixSum[n][k]
        vector<vector<long long>> prefixSum(
            n, vector<long long>(k + 1, 0)
        );

        // Base cases
        for (int i = 0; i < n; i++) {
            // 0 segments = 1 way
            dp[i][0] = 1;

            // prefix sum of dp[0][0] ... dp[i][0]
            prefixSum[i][0] = i + 1;
        }

        // O(N * K)
        for (int i = 1; i < n; i++) {

            for (int j = 1; j <= k; j++) {

                // NO PICK
                dp[i][j] = dp[i - 1][j];

                // PICK
                dp[i][j] += prefixSum[i - 1][j - 1];
                dp[i][j] %= MOD;

                // Update prefix sum
                prefixSum[i][j] =
                    (prefixSum[i - 1][j] + dp[i][j]) % MOD;
            }
        }

        return dp[n - 1][k];
    }
};