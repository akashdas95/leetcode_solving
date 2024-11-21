class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> v(n, vector<int> (n));
        if(n == 0){
            return {};
        }
        int row_start = 0, row_end = n - 1;
        int col_start = 0, col_end = n - 1;

        int i = 1;
        while (row_start <= row_end && col_start <= col_end) {
            for (int col = col_start; col <= col_end; col++) {
                v[row_start][col] = i;
                i++;
            }
            row_start++;

            for (int row = row_start; row <= row_end; row++) {
                v[row][col_end] = i;
                i++;
            }
            col_end--;

            if (row_start <= row_end) {
                for (int col = col_end; col >= col_start; col--) {
                    v[row_end][col] = i;
                    i++;
                }
                row_end--;
            }

            if (col_start <= col_end) {
                for (int row = row_end; row >= row_start; row--) {
                    v[row][col_start] = i;
                    i++;
                }
                col_start++;
            }
        }
        return v;
    }
};
