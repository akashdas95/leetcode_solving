class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int n = words.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            string str = s.substr(0, words[i].size());
            if (words[i] == str) {
                count++;
            }
        }
        return count;
    }
};