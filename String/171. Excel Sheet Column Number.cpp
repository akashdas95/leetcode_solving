class Solution {
public:
    int titleToNumber(string c) {
        int res = 0;
        for(int i=0; i<c.size(); i++){
            res *= 26;
            res += (c[i] - 'A') +1;
        }
        return res;
    }
};