class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        stack<char>st;
        char ch;
        for(int i=0;i<s.size();i++){
            ch = s.at(i);
            if(ch=='('){
                if(st.size()>0){
                    ans+=ch;
                }
                st.push(ch);
            }
            else{
                st.pop();
                if(!st.empty()){
                    ans+=ch;
                }
            }
        }
        return ans;
    }
};