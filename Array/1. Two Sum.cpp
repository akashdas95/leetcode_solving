class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int remaining;
        vector<int>v;
        for(int i=0; i<nums.size();i++){
            int j= i+1;
            remaining = target-nums[i];
            while(j<nums.size()){
                if(nums[j]==remaining){
                    v.push_back(i);
                    v.push_back(j);
                    //break;
                }
                j++;
            }
        }
        return v;
    };
};