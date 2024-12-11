class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int oddCnt = 0;
        int result = 0;
        mp[0] = 1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] & 1) {
                oddCnt++;
            }

            if (mp.count(oddCnt - k)) {
                result += mp[oddCnt - k];
            }

            mp[oddCnt]++;
        }
        return result;
    }
};