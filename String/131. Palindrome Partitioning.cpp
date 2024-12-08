class Solution {
public:
    bool isPalindrome(int start, int end, string s){
        while(start<=end){
            if(s[start]!=s[end]){
                return false;
            }
            start++,end--;
        }
        return true;
    }
    void palindromePartition(int idx, string s, vector<vector<string>>& ans, vector<string>& v) {
        if (idx == s.size()) {
            ans.push_back(v);
            return;
        }
        for (int i = idx; i < s.size(); i++) {
            if (isPalindrome(idx, i, s)) {
                v.push_back(s.substr(idx, i - idx + 1));
                palindromePartition(i + 1, s, ans, v);
                v.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> v;
        palindromePartition(0, s, ans, v);
        return ans;
    }
};