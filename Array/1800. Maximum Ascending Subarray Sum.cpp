class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sum = 0;
        int maxSum = 0;
        if (nums[0] < nums[1]) {
            sum += nums[0];
        }

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i-1] < nums[i]) {
                sum += nums[i];
            } else {
                sum = nums[i];
            }
            maxSum = max(maxSum, sum);
        }
        return maxSum > nums[0] ? maxSum : nums[0];
    }
};