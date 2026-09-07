class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1000000007;
        long long total = 0;
        vector<long long> end(26, 0);
        for (char ch : s) {
            int index = ch - 'a';
            long long newSubsequence =
                (total + 1 - end[index] + MOD) % MOD;
            end[index] = (total + 1) % MOD;
            total = (total + newSubsequence) % MOD;
        }
        return (int)total;
    }
};