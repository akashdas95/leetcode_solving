class Solution {
public:
    bool canJump(vector<int>& nums) {
        int can_jump = 0;
        for(int i=0;i<=can_jump; i++){
            if(i==nums.size()-1){
                return true;
            }
            can_jump = max(can_jump, i+nums[i]);
        }
        return false;
    }
};

//solution from errictho