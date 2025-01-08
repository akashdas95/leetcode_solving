class Solution {
public:
    bool isPrefixAndSuffix(string &str1, string &str2) {
        if (str1.size() > str2.size()) {
            return false;
        }
        string s1 = str2.substr(0,str1.size());
        string s2 = str2.substr(str2.size() - str1.size(), str1.size());
        return s1 == str1 && s2 == str1;;
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int count = 0;
        for (int i = 0; i < n-1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isPrefixAndSuffix(words[i], words[j])) {
                    count++;
                }
            }
        }
        return count;
    }
};