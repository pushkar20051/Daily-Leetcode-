class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> rightMin(n);
        rightMin[n-1] = nums[n-1];
        for (int i = n-2 ; i >= 0 ; i--){
            rightMin[i] = min(nums[i], rightMin[i+1]);
        }
            int leftMax = INT_MIN;

            for (int i = 0; i < n ; i++){
                leftMax = max(nums[i], leftMax);
            int instability = leftMax - rightMin[i]; 
            if (k >= instability) { 
                return i; 
            }
        }
        return -1;
    }
};