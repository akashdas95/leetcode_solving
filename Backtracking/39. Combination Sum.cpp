class Solution {
public:

    void combinations(int idx, int target, vector<int>& candidates, vector<vector<int>>&ans, vector<int>&v){
       if(idx==candidates.size()){
           if(target==0){
               ans.push_back(v);
           }
           return;
       }
       if(candidates[idx]<=target){                     //pick element
           v.push_back(candidates[idx]);
           combinations(idx, target-candidates[idx], candidates, ans, v);
           v.pop_back();
       }
       combinations(idx+1, target, candidates, ans, v);  //not picking the element
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>v;
        combinations(0,target,candidates,ans,v);
        return ans;
    }
};