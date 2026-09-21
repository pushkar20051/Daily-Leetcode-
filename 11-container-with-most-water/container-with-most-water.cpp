class Solution {
public:
    int maxArea(vector<int>& height) {
        int n= height.size();
        int left = 0 ;
        int right = n-1;
        int maxArea = INT_MIN; 
        while (left < right){
            int length = right - left  ;
            int minHeight = min(height[left] , height[right]);
            int area = length * minHeight;
            maxArea = max(maxArea , area);
            if(height[left]< height[right]) left++;
            else right--;
        }
        return maxArea;
    }
};