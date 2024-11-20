class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();
        int aCount = 0, bCount = 0, cCount = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') {
                aCount++;
            } else if (s[i] == 'b') {
                bCount++;
            } else {
                cCount++;
            }
        }
        if (aCount < k || bCount < k || cCount < k) {
            return -1;
        }
        int i = 0, j = 0, notDeleteWindowSize = 0;
        while (j < n) {
            if (s[j] == 'a') {
                aCount--;
            } else if (s[j] == 'b') {
                bCount--;
            } else {
                cCount--;
            }

            while (i <= j && (aCount < k || bCount < k || cCount < k)) {
                if (s[i] == 'a') {
                    aCount++;
                } else if (s[i] == 'b') {
                    bCount++;
                } else {
                    cCount++;
                }
                i++;
            }
            notDeleteWindowSize = max(notDeleteWindowSize, j - i + 1);
            j++;
        }
        return n - notDeleteWindowSize;
    }
};