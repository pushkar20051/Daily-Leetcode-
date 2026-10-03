class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> ans;
        int left = 0;
        int right = col-1;
        int up = 0;
        int down = row-1;
        while(up <= down && left <= right ){
            //right 
            for(int j = left ; j <= right ; j++){
                ans.push_back(matrix[up][j]);
            }
            up++;
            //down
            for(int i = up ; i <= down ; i++ ){
                ans.push_back(matrix[i][right]);
            }
            right--;
            //left
            if(up <= down ){
                for(int j = right ; j >= left ; j--){
                    ans.push_back(matrix[down][j]);
                }
                down--;
            }
            //up
            if(left <= right){
                for(int i = down ; i >= up ; i--){
                    ans.push_back(matrix[i][left]);
                }
                left++; 
            }
        }
        return ans;
    }
};