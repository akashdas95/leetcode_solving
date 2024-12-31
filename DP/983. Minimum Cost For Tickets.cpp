//using recursion and memoization
class Solution {
public:
    int t[366];

    int solve(vector<int>& days, vector<int>& costs, int n, int i) {
        if (i >= n) {
            return 0;
        }

        if(t[i] != -1){
            return t[i];
        }
        // for 1 day pass
        int oneDayPass = costs[0] + solve(days, costs, n, i + 1);

        // for 7 days pass
        int j = i;
        int max_day = days[i] + 7;
        while (j < n && days[j] < max_day) {
            j++;
        }
        int sevenDayPass = costs[1] + solve(days, costs, n, j);

        // for 1 month pass
        j = i;
        max_day = days[i] + 30;
        while (j < n && days[j] < max_day) {
            j++;
        }
        int oneMonthPass = costs[2] + solve(days, costs, n, j);

        return t[i] =  min({oneDayPass, sevenDayPass, oneMonthPass});
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        memset(t, -1, sizeof(t));
        return solve(days, costs, n, 0);
    }
};


//using tableau method
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_set<int> st(begin(days), end(days));
        int last_day = days.back();
        vector<int> t(last_day + 1, 0);

        for (int i = 1; i <= last_day; i++) {
            if (st.find(i) == st.end()) {
                t[i] = t[i - 1];
                continue;
            }

            int oneDayPass = costs[0] + t[max(i - 1, 0)];
            int sevenDayPass = costs[1] + t[max(i - 7, 0)];
            int oneMonthPass = costs[2] + t[max(i - 30, 0)];

            t[i] = min({oneDayPass, sevenDayPass, oneMonthPass});
        }

        return t[last_day];
    }
};