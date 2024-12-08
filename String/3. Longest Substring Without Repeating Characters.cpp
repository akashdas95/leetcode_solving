class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>mp(256,-1);
        int l =0, r=0,len = 0;

        while(r<s.size()){
            if(mp[s[r]] != -1){
                l= max(l,mp[s[r]]+1);
            }
            mp[s[r]] = r;
            len = max(len,(r-l+1));
            r++;
        }

        return len;
    }
};