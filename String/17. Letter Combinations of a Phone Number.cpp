class Solution {
public:

    void Combinations(int idx, string &digits, unordered_map<char,string>&mp, string &temp, vector<string>&st){
        if(idx>=digits.size()){
            st.push_back(temp);
            return;
        }
        char ch = digits[idx];
        string str = mp[ch];

        for(int i=0; i<str.size(); i++){
            temp.push_back(str[i]);
            Combinations(idx+1,digits,mp,temp,st);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0){
            return {};
        }
        string temp = "";
        vector<string>st;
        unordered_map<char,string>mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        Combinations(0,digits,mp,temp,st);
        return st;
    }
};