class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 0 ; i< n ; i++){
            for(int j = i+1 ; j< m ; j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        for(int i = 0 ; i< n ; i++){
            int j = 0;
            int k = m-1; 
            while(j < k ){
                int temp = matrix[i][j];
                matrix[i][j]= matrix[i][k];
                matrix[i][k] = temp;
                k--;
                j++;
            }
        }
    }
};