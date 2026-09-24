class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int m = nums.size();
        for(int i=0;i<m;i++){
            if(nums[i] >9){
                int n = nums[i];
                int sum =0;
                while(n >0){
                    int first = n % 10;
                    sum += first;
                    n /= 10;
                }
                if(sum == i) return i;
            }
            else{
                if(nums[i] == i) return i;
            }
        }
        return -1;
    }
};