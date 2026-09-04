class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        for (int index = 0 ; index < n ; index++){
            int max = INT_MIN;
            int min = INT_MAX;

            for (int i = 0; i <= index ; i++){
                max = std :: max(max , nums[i]);
            }
            for (int j = index ; j < n ; j++){
                min = std :: min(min , nums[j]);
            }
            int instability = max - min ; 
            if (k >= instability) { 
                return index; 
            }
        }
        return -1;
    }
};