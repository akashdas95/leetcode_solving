class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0, r=0, sums=0;
        int ans= 2e9;
        while(r<nums.size()){
            sums+=nums[r];
            while(sums >= target){
                ans= min(r-l+1, ans);
                sums-=nums[l];
                l++;
            }
            r++;
    
        }

        if(ans==2e9){
            return 0;
        }
        else{
            return ans;
        }       
    }
};