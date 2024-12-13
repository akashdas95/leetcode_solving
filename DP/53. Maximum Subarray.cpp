class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=-2e9,sum=-2e9;
        for (int i=0;i<nums.size();i++){
           sum=max(nums[i],sum+nums[i]);
           ans=max(ans,sum);
        }
        return ans;
    }
};