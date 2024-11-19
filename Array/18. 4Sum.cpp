class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& n, int target) {
        sort(begin(n), end(n));
        int s = n.size();
        vector<vector<int>> ans;

        for (int i = 0; i < s; i++) {
            if (i > 0 && n[i] == n[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < s; j++) {
                if (j != i + 1 && n[j] == n[j - 1]) {
                    continue;
                }
                int k = j + 1;
                int l = s - 1;
                while (k < l) {
                    long sum = n[i] + n[j] + n[k];
                    sum += n[k];
                    sum += n[l];
                    if (sum == target) {
                        vector<int> temp = {n[i], n[j], n[k], n[l]};
                        ans.push_back(temp);
                        k++, l--;
                        while (k < l && n[k] == n[k - 1]) {
                            k++;
                        }
                        while (k < l && n[l] == n[l + 1]) {
                            l--;
                        }
                    } else if (sum < target) {
                        k++;
                    } else {
                        l--;
                    }
                }
            }
        }
        return ans;
    }
};