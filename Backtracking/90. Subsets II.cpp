class Solution {
public:
   void subset(int idx, vector<int>&v, vector<int>& nums, vector<vector<int>>&ans){
       ans.push_back(v);
       for(int i=idx;i<nums.size();i++){
           if(i!=idx && nums[i]==nums[i-1]){
               continue;
           }
           v.push_back(nums[i]);
           subset(i+1, v, nums, ans);
           v.pop_back();
       }
   }


    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>v;
        subset(0,v,nums,ans);
        return ans;
    }
};