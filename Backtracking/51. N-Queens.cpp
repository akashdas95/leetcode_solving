class Solution {
public:

    void solve(int col, int n, vector<vector<string>>&ans, vector<string>&board, vector<int>&leftrow, vector<int>&upperDiagonal, vector<int>&lowerDiagonal){
       if(col == n){
           ans.push_back(board);
           return;
       }
       for(int row=0; row<n; row++){
           if(leftrow[row]==0 && lowerDiagonal[row+col]==0 && upperDiagonal[n-1 +col-row]==0){
               board[row][col]='Q';
               leftrow[row]=1;
               lowerDiagonal[row+col]= 1;
               upperDiagonal[n-1 +col-row]= 1;
               solve(col+1, n, ans, board, leftrow, upperDiagonal, lowerDiagonal);
               board[row][col]='.';
               leftrow[row]=0;
               lowerDiagonal[row+col]= 0;
               upperDiagonal[n-1 +col-row]= 0;
           }
       }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0; i<n;i++){
            board[i]=s;
        }
        vector<int>leftrow(n,0), upperDiagonal((2*n)-1, 0), lowerDiagonal((2*n)-1, 0);
        solve(0, n, ans, board, leftrow, upperDiagonal, lowerDiagonal);
        return ans; 
    }
};