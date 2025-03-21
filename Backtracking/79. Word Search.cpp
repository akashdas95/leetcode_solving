class Solution {
public:
    bool WSearch(vector<vector<char>>& board,int i,int j,string &word,int idx){
        if(idx == word.size()-1){
            return true;
        }
        board[i][j]-= 65;

        //top index check
        if(i>0 && board[i-1][j]==word[idx+1] && WSearch(board,i-1,j,word,idx+1)){
            return true;
        }
        //left index check
        if(j>0 && board[i][j-1]==word[idx+1] && WSearch(board,i,j-1,word,idx+1)){
            return true;
        }
        //right index check
        if(j<board[0].size()-1 && board[i][j+1]==word[idx+1] && WSearch(board,i,j+1,word,idx+1)){
            return true;
        }
        //bottom index check
        if(i<board.size()-1 && board[i+1][j]==word[idx+1] && WSearch(board,i+1,j,word,idx+1)){
            return true;
        }
        board[i][j] += 65;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int r = board.size();
        int c = board[0].size();

        for(int i=0;i<r;i++){
            for(int j=0; j<c;j++){
                if(board[i][j]== word[0] && WSearch(board,i,j,word,0)){
                    return true;
                }
            }
        }
        return false;
    }
};