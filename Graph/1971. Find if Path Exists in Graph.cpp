class Solution {
public:

    bool dfs(int node, unordered_map<int,vector<int>>&adjList, int destination, vector<bool>&vis){
       if(node == destination){
           return true;
       }
       if(vis[node]){
           return false;
       }
       vis[node] = true;
       for(auto &it: adjList[node]){
           if(dfs(it,adjList,destination,vis)){
               return true;
           }
       }
       return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,vector<int>>adjList;
        for(vector<int> &edge : edges){ 
            int u = edge[0];
            int v = edge[1]; 
            adjList[u].push_back(v);
            adjList[v].push_back(u);    
        }
        vector<bool>vis(n,false);
        return dfs(source,adjList,destination,vis);
    }
};