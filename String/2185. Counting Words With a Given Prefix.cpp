class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n = words.size();
        int count = 0;
        for(int i=0; i<n; i++){
            string s = words[i].substr(0,pref.size());
            if(s == pref){
                count++;
            }
        }
        return count;
    }
};