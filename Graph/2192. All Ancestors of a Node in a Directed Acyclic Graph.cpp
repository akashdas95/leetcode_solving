class Solution {
public:
    void dfs(int ancestor, int currNode, unordered_map<int, vector<int>>& adj,
             vector<vector<int>>& res) {
        for (auto& ngbr : adj[currNode]) {
            if (res[ngbr].empty() || res[ngbr].back() != ancestor) {
                res[ngbr].push_back(ancestor);
                dfs(ancestor, ngbr, adj, res);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> res(n);
        unordered_map<int, vector<int>> adj;

        for (vector<int> vec : edges) {
            int u = vec[0];
            int v = vec[1];

            adj[u].push_back(v);
        }

        for (int i = 0; i < n; i++) {
            int ancestor = i;
            dfs(ancestor, i, adj, res);
        }

        return res;
    }
};