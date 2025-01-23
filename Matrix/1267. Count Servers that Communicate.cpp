//Brute Force
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int count = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1) {
                    bool canCommunicate = false;
                    // check row
                    for (int k = 0; k < r; k++) {
                        if (grid[k][j] == 1 && k != i) {
                            canCommunicate = true;
                            break;
                        }
                    }
                    if (canCommunicate) {
                        count++;
                    } else {
                        // check col
                        for (int k = 0; k < c; k++) {
                            if (grid[i][k] == 1 && k != j) {
                                count++;
                                break;
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};


//Optimal
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int count = 0;
        vector<int>rowServerCount(r,0);
        vector<int>colServerCount(c,0);
        for (int i = 0; i < r; i++) {
            for(int j=0; j<c; j++){
                if(grid[i][j] == 1){
                    rowServerCount[i]++;
                    colServerCount[j]++;
                }
            }
        }

        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(grid[i][j] == 1 && (rowServerCount[i]> 1 || colServerCount[j] > 1)){
                    count++;
                }
            }
        }
        return count;
    }
};