class Solution {
public:

    void dfs(vector<vector<int>>& graph, int node, int target, vector<vector<int>>&res, vector<int>&temp){
        temp.push_back(node);
        if(node == target){
           res.push_back(temp);
        }
        else{
            for(auto &it: graph[node]){
                dfs(graph,it,target,res,temp);
            }
        }
        temp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int start = 0, target = graph.size()-1;
        vector<vector<int>>res;
        vector<int>temp;
        dfs(graph, start, target, res, temp);
        return res;
    }
};