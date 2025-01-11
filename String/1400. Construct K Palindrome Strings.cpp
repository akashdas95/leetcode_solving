//c++
class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.size() < k) {
            return false;
        }
        vector<int> vec(26, 0);
        for (int i = 0; i < s.size(); i++) {
            vec[s[i] - 'a']++;
        }
        int count = 0;
        for (int i = 0; i < 26; i++) {
            if (vec[i] % 2 == 1) {
                count++;
            }
        }
        if (count > k) {
            return false;
        }
        return true;
    }
};


//java
class Solution {
    public boolean canConstruct(String s, int k) {
        if(s.length() < k){
            return false;
        }
        int[] freq = new int[26];
        for(int i=0; i<s.length(); i++){
            freq[s.charAt(i)-'a']++;
        }
        int count = 0;
        for(int i=0; i<26; i++){
            if(freq[i] % 2 == 1){
                count++;
            }
        }
        if(count > k){
            return false;
        }
        return true;
    }
}