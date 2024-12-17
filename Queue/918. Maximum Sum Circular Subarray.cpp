class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int currMax= 0, currMin = 0, total = 0;
        int globalMax = nums[0], globalMin = nums[0];

        for(int i=0; i<nums.size(); i++){
            currMax = max(nums[i],currMax+nums[i]);
            currMin = min(nums[i],currMin+nums[i]);
            total += nums[i];
            globalMax = max(currMax,globalMax);
            globalMin = min(currMin,globalMin);
                        
        }
        if(globalMax < 0){
            return globalMax;
        }
        
        return max(total - globalMin, globalMax);
    }
};