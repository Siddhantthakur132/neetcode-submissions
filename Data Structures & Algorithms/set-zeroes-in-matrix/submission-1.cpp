class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
         int r = matrix.size();
        int c = matrix[0].size();
        vector<vector<int>> mark = matrix;

        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(matrix[i][j] == 0) {
                    // पूरी रो (Row) को 0 करें
                    for(int col = 0; col < c; col++) {
                        mark[i][col] = 0;
                    }
                    // पूरे कॉलम (Column) को 0 करें
                    for(int row = 0; row < r; row++) {
                        mark[row][j] = 0;
                    }
                }
            }
        }

        // बदलावों को वापस matrix में कॉपी करें
        matrix = mark; 
    }
};
