class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        vector<int> vec(n,0);
        vec[0] = values[0] + 0;
        for (int i = 1; i < n; i++) {
            vec[i] = max(vec[i - 1], values[i] + i);
        }

        int res = 0;
        for (int j = 1; j < n; j++) {
            int x = vec[j - 1];
            int y = values[j] - j;
            res = max(res, x + y);
        }
        return res;
    }
};