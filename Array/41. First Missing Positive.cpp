class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
       for(int i=0;i<nums.size();i++){
         if(nums[i]<0){
            nums[i] = 0;
         }
       }

       for(int i=0;i<nums.size();i++){
        int idx = abs(nums[i]);
         if(idx>0 && idx <=nums.size()){ 
            if(nums[idx-1]>0){
                nums[idx-1] *= -1; 
            }
            else if(nums[idx-1]==0){
                nums[idx-1] = -1*nums.size();
            }
         }
       }
       for(int i=1;i<=nums.size(); i++){
          if(nums[i-1] >= 0){
            return i;
          }
       }
       return nums.size()+1; 
    }
};