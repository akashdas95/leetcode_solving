
class Solution {
public:
    bool isPrefix(string word, string srcWord){
        if(srcWord.size()>word.size()){
            return false;
        }
        for(int i=0; i<srcWord.size(); i++){
            if(srcWord[i] != word[i]){
                return false;
            }
        }
        return true;
    }

    int isPrefixOfWord(string sen, string srchWord) {
        vector<string>words;
        int i = 0;
        while(i<sen.size()){
            string sub = "";
            while(i<sen.size() && sen[i]!= ' '){
                sub+=sen[i];
                i++;
            }
            words.push_back(sub);
            i++;
        }
        int ind = 0;
        for(string word : words){
            if(isPrefix(word,srchWord)){
                return ind+1;
            }
            ind++;
        }
        return -1;
    }
};