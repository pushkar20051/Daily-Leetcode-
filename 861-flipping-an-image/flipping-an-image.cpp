class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int row = image.size();
        int col = image[0].size();
        for(int i=0;i<row;i++){
            int j =0;
            int k =col-1;
            while(j < k){
                int temp = image[i][j];
                image[i][j] = image[i][k];
                image[i][k] = temp;
                k--;
                j++;
            }
        }

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(image[i][j] == 0) image[i][j] = 1;
                else image[i][j] = 0;
            }
        }
        return image;
    }
};