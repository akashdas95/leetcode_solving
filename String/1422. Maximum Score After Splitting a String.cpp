// brute force O(n2)
class Solution {
public:
    int maxScore(string s) {
        int result = INT_MIN;

        for (int i = 0; i < s.size() - 1; i++) {
            int zero_count = 0;
            for (int j = 0; j <= i; j++) {
                if (s[j] == '0') {
                    zero_count++;
                }
            }
            int one_count = 0;
            for (int j = i + 1; j < s.size(); j++) {
                if (s[j] == '1') {
                    one_count++;
                }
            }

            result = max(result, zero_count + one_count);
        }
        return result;
    }
};


//optimal O(n)
class Solution {
public:
    int maxScore(string s) {
        int result = INT_MIN;
        int total_one = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                total_one++;
            }
        }

        int zero_count = 0;
        int one_count = 0;
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == '0') {
                zero_count++;
            }
            else{
                one_count++;
            }

            result = max(result, zero_count + (total_one - one_count));
        }
        return result;
    }
};