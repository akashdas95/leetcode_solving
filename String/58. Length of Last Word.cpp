class Solution {
public:
    int lengthOfLastWord(string s) {
        int cnt = 0;
        int n= s.size()-1;
        while(n>=0){
            if(s[n]== ' ' && cnt>0){
                break;
            }
            else if(s[n]== ' '){
                n--;
            }
            else{
                cnt++;
                n--;
            }
        }
        return cnt;
    }
};