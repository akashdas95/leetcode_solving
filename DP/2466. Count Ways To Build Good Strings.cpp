class Solution {
public:
    int L, H, Z, O;
    const int M = 1e9 + 7;

    int stringCount(int length, vector<int>&t) {
        if (length > H) {
            return 0;
        }
        if(t[length] != -1){
            return t[length];
        }
        
        bool addOne = false;
        if (length >= L) {
            addOne = true;
        }

        int add_zero = stringCount(length + Z,t);
        int add_one = stringCount(length + O,t);
        return t[length] = (addOne + add_zero + add_one) % M;
    }

    int countGoodStrings(int l, int h, int z, int o) {
        L = l;
        H = h;
        Z = z;
        O = o;
        vector<int>t(h+1, -1);
        return stringCount(0,t);
    }
};