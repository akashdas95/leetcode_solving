//Brute Force
//TLE
class Solution {
public:

    bool checkRowPainted(vector<vector<int>>& mat, int row) {
        for(int col = 0; col < mat[0].size(); col++) {
            if(mat[row][col] > 0) { 
                return false;
            }
        }

        return true;
    }

    bool checkColPainted(vector<vector<int>>& mat, int col) {
        for(int row = 0; row < mat.size(); row++) {
            if(mat[row][col] > 0) { 
                return false;
            }
        }

        return true;
    }

    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        unordered_map<int, pair<int, int>> mp; 

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int val = mat[i][j];
                mp[val] = {i, j};
            }
        }

        for(int i = 0; i < arr.size(); i++) {
            int val = arr[i];

            auto [row, col] = mp[val];
            mat[row][col] *= -1; 

            if(checkRowPainted(mat, row) || checkColPainted(mat, col)) {
                return i;
            }
        }

        return -1;

    }
};




// Better approch
class Solution {
public:

    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        unordered_map<int, pair<int, int>> mp; 

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int val = mat[i][j];
                mp[val] = {i, j};
            }
        }

        vector<int> rowCountPaint(m, 0); 
        vector<int> colCountPaint(n, 0); 

        for(int i = 0; i < arr.size(); i++) {
            int val = arr[i];
            auto [row, col] = mp[val];

            rowCountPaint[row]++;
            colCountPaint[col]++;

            if(rowCountPaint[row] == n || colCountPaint[col] == m) {
                return i;
            }
        }
        return -1;
    }
};