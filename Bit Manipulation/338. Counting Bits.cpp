class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>v(n+1,0);
        int offset = 1;
        for(int i=1;i<=n;i++){
            if(i%2==0){
                v[i] = v[i>>1];
            }
            else{
                v[i] =1+ v[i>>1];
            }
        }
        return v;
    }
};