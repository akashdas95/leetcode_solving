class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();
        if(len1<=0){
            return word2;
        }
        if(len2<=0){
            return word1;
        }
        string word3 = "";
        int i=0; 
        while(i<len1 && i<len2){
            word3+= word1[i];
            word3+= word2[i];
            i++;
        }

        while(i<len1){
            word3 += word1[i];
            i++;
        }
        while(i<len2){
            word3+= word2[i];
            i++;
        }

        return word3;
    }
};