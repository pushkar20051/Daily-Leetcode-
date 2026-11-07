class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int n = nums.size();
        int largest = -1 ; 
        for(int i = 0 ; i< n ; i++){
            for(int j = n-1 ; j >= 0 ; j--){
                if (nums[i] == -nums[j]) {
                    largest = max(largest, abs(nums[i]));
                    
                }
            }
        }
        return largest;
    }
};