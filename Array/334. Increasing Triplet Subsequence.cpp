//C++
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        int num1 = nums[0];
        int num2 = INT_MAX;
        int num3 = nums[0];
        for (int i = 1; i < n; i++) {
            num3 = nums[i];
            if (num3 <= num1) {
                num1 = num3;
            } else if (num3 <= num2) {
                num2 = num3;
            } else {
                return true;
            }
        }
        return false;
    }
};


//java
class Solution {
    public boolean increasingTriplet(int[] nums) {
        int n = nums.length;
        int num1 = nums[0];
        int num2 = Integer.MAX_VALUE;
        int num3 = nums[0];
        for(int i = 1; i<n; i++){
            num3 = nums[i];
            if(num3<=num1){
                num1 = num3;
            }
            else if(num3 <= num2){
                num2 = num3;
            }
            else{
                return true;
            }
        }
        return false;
    }
}