class Solution {
public:
    
    void generateP(int openCnt, int closeCnt, int n, string curr, vector<string>&v){
        if(openCnt == n && closeCnt == n){
            v.push_back(curr);
        }
        else{
            if(openCnt<n){
                generateP(openCnt+1,closeCnt,n,curr+"(",v);
            }
            if(closeCnt<openCnt){
                generateP(openCnt,closeCnt+1,n,curr+")",v);
            }

        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>v;
        generateP(0,0,n,"",v);
        return v;
    }
};