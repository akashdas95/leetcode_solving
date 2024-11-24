class Solution {
public:
    vector<string>v;
    void generateP(int openCnt, int closeCnt, int n, string curr){
        if(openCnt == n && closeCnt == n){
            v.push_back(curr);
        }
        else{
            if(openCnt<n){
                generateP(openCnt+1,closeCnt,n,curr+"(");
            }
            if(closeCnt<openCnt){
                generateP(openCnt,closeCnt+1,n,curr+")");
            }

        }
    }
    vector<string> generateParenthesis(int n) {
        generateP(0,0,n,"");
        return v;
    }
};