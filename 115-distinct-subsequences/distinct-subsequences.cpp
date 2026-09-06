class Solution {
public:

    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();

        vector<vector<long long>> dp(n, vector<long long>(m, -1));

        return solve(s, t, 0, 0, dp);
    }

    long long solve(string& s, string& t, int i, int j, vector<vector<long long>>& dp) {
        if (j == t.length()) return 1;
        if (i == s.length()) return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == t[j]) {
            long long pick = solve(s, t, i + 1, j + 1, dp);
            long long noPick = solve(s, t, i + 1, j, dp);
            return dp[i][j] = pick + noPick;
        }
        // Characters don't match, so skip s[i]
        return dp[i][j] = solve(s, t, i + 1, j, dp);
    }
};