class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(0);
        stack<int> st;

        for (int i = temperatures.size() - 1; i >= 0; i--) {
            while (!st.empty() && temperatures[st.top()] <= temperatures[i]) {
                st.pop();
            }
            if (!st.empty() && temperatures[st.top()] >= temperatures[i]) {
                ans.push_back(st.top() - i) ;
            }
            if (st.empty()) {
                ans.push_back(0);
            }
            st.push(i);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};