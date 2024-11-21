class Solution {
public:
    int m;
    int n;
    vector<int>direction={-1,0,1};
    
    int dfs(int r, int c, vector<vector<int>>& grid, vector<vector<int>>&t){
        if(t[r][c]!=-1){
            return t[r][c];
        }
        int moves = 0;
        for(int &dir : direction){
            int newR = r+dir;
            int newC = c+1;
            if(newR>=0 && newR<m && newC>=0 && newC<n && grid[newR][newC]>grid[r][c]){
                moves = max(moves, 1+dfs(newR,newC,grid,t));
            }
        }
        return t[r][c] = moves;
    }

    int maxMoves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int res = 0;
        vector<vector<int>>t(m,vector<int>(n,-1));
        for(int i=0; i<m; i++){
            res = max(res,dfs(i,0,grid,t));
        }
        return res;
    }
};