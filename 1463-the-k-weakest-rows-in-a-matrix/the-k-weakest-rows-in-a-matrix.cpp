class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> soldiers(n, vector<int>(2));
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1)
                    count++;
            }
            soldiers[i][0] = count;
            soldiers[i][1] = i;
        }
        sort(soldiers.begin(), soldiers.end(),
            [](const vector<int>& a, const vector<int>& b) {
                if (a[0] == b[0])
                    return a[1] < b[1];

                return a[0] < b[0];
            });
        vector<int> ans(k);
        for (int i = 0; i < k; i++) {
            ans[i] = soldiers[i][1];
        }
        return ans;
    }
};