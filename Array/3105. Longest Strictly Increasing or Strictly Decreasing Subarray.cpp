class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int increasing = 1;
        int decreasing = 1;
        int increased = 1, decreased = 1;
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i]< nums[i+1]){
                increasing++;
            }else{
                increasing = 1;
            }
            increased = max(increased, increasing);
        }
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i] > nums[i+1]){
                decreasing++;
            }else{
                decreasing = 1;
            }
            decreased = max(decreased, decreasing);
        }
        return increased > decreased ? increased : decreased; 
        
    }
};