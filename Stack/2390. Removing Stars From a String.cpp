class Solution {
public:
    string removeStars(string s) {
        stack<char>stk;
        string ans = "";
        for(int i=0; i<s.size();i++){
           if(!stk.empty() && s[i] == '*'){
               stk.pop();
           }
           else{
               stk.push(s[i]);  
            } 
        }

        while(!stk.empty()){
            ans.push_back(stk.top());
            stk.pop();
        }
        reverse(begin(ans),end(ans));
        return ans;
    }
};