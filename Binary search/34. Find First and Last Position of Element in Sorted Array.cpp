class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        int First_position =-1, Last_position =-1;
        while(l<=r){
            int mid = (l+r)/2;
            if(nums[mid]==target){
                First_position = mid;
                r=mid-1;
            }
            else if(nums[mid]<target){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        int i=0, j=nums.size()-1;
        while(i<=j){
            int mid = (i+j)/2;
            if(nums[mid]==target){
                Last_position = mid;
                i=mid+1;
            }
            else if(nums[mid]>target){
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        return {First_position,Last_position};
    }
};