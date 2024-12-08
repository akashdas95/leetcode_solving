class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size()>haystack.size()){
            return -1;
        }
        
        for(int i=0; i<haystack.size(); i++){
            int j=0;
            if(haystack[i] == needle[j]){
                int k = i;
                while(j < needle.size()){
                    if(haystack[k]==needle[j]){
                       k++,j++;
                    }
                    else{
                        break;
                    }
                   
                }
                if(j == needle.size()){
                    return i;
                }
            }
        }
        return -1;
    }
};