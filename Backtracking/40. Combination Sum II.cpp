class Solution {
public:

    void combinationSum(int idx, int target, vector<int>& candidates, vector<vector<int>>&ans, vector<int>&v){
        if(target==0){
            ans.push_back(v);
            return;
        }
        for(int i =idx; i<candidates.size();i++){
            if(idx!=i && candidates[i]==candidates[i-1]){
                continue;
            }
            if(candidates[i]>target){
                break;
            }
            v.push_back(candidates[i]);
            combinationSum(i+1,target-candidates[i],candidates,ans,v);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
       sort(candidates.begin(),candidates.end());
       vector<vector<int>>ans;
       vector<int>v;
       combinationSum(0,target,candidates,ans,v);
       return ans; 
    }
};