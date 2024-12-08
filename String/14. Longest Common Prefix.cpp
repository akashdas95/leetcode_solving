class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        if(strs.size() == 0){
            return ans;
        }
        sort(strs.begin(),strs.end());
        string str1 = strs[0];
        string str2 = strs[strs.size()-1];
        for(int i=0; i<strs[0].size(); i++){
            if(str1[i]!=str2[i]){
                break;
            }
            ans+=str1[i];
        }
        return ans;
    }
};