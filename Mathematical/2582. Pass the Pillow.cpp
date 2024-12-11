class Solution {
public:
    int passThePillow(int n, int time) {
        int pos = 1;
        int direc = 1;

        while (time > 0) {
            if (pos + direc >= 1 && pos + direc <= n) {
                pos += direc;
                time--;
            } else {
                direc *= -1;
            }
        }
        return pos;
    }
};



class Solution {
public:
    int passThePillow(int n, int time) {
        int full_round = time / (n - 1);
        int pass_left = time % (n - 1);
        return full_round % 2 == 1 ? n - pass_left : pass_left + 1;
    }
};