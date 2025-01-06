class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans(n, 0);

        for (int i = 0; i < n; i++) {
            if (boxes[i] == '1') {
                for (int j = 0; j < n; j++) {
                    int moves = abs(i - j);
                    ans[j] = ans[j] + moves;
                }
            }
        }
        return ans;
    }
};


class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans(n, 0);
        unordered_set<int> st;
        for (int i = 0; i < n; i++) {
            if (boxes[i] == '1') {
                st.insert(i);
            }
        }

        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (auto& ele : st) {
                sum += abs(i - ele);
            }
            ans[i] = sum;
        }
        return ans;
    }
};