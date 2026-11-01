class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int mn = INT_MAX;
        for(int i=0;i<n;i++){
            mn = min(mn, nums[i]);
        }
        int moves =0;
        for(int i=0;i<n;i++){
            moves += (nums[i] - mn);
        }
        return moves;
    }
};