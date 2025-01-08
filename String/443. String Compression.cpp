class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int index = 0;
        int i = 0;
        while(i<n){
            char curr_ch = chars[i];
            int count = 0;
            while(i<n && chars[i] == curr_ch){
                count++;
                i++;
            }
            chars[index] = curr_ch;
            index++;
            if(count > 1){
                string curr_count = to_string(count);
                for(char &ch : curr_count){
                    chars[index]= ch;
                    index++;
                }
            }
        }
        return index;
    }
};