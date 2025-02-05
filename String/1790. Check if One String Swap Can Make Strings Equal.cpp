//C++
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1 == s2){
            return true;
        }

        vector<int>vec1(26,0);
        vector<int>vec2(26,0);
        
        for(int i=0; i<s1.size(); i++){
            vec1[s1[i] - 'a']++;
        }
        for(int i=0; i<s2.size(); i++){
            vec2[s2[i] - 'a']++;
        }
        bool swap = true;

        for(int i=0; i<26; i++){
            if(vec1[i] != vec2[i]){
                swap = false;
            }
        }

        int swapedPlace = 0;
        for(int i=0; i<s1.size(); i++){
            if(s1[i] != s2[i]){
                swapedPlace++;
            }
        }
        return (swapedPlace <= 2 && swap) ? true : false;
    }
};







//JAVA
class Solution {
    public boolean areAlmostEqual(String s1, String s2) {
        if(s1 == s2){
            return true;
        }

        int []freq1 = new int[26];
        int []freq2 = new int[26];
        int swapedPlace = 0;

        for(int i=0; i<s1.length(); i++){
            if(s1.charAt(i)!=s2.charAt(i)){
                swapedPlace++;
            }

            if(swapedPlace >2){
                return false;
            }

            freq1[s1.charAt(i) - 'a']++;
            freq2[s2.charAt(i) - 'a']++;
        }

        for(int i=0; i<26; i++){
            if(freq1[i] != freq2[i]){
                return false;
            }
        }
        return true;
    }
}