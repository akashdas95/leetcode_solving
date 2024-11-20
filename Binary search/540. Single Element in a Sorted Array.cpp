class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            bool isEven = false;
            if ((r - mid) % 2 == 0) {
                isEven = true;
            }
            if (nums[mid] == nums[mid + 1]) {
                if (isEven) {
                    l = mid + 2;
                } else {
                    r = mid - 1;
                }
            } else {
                if (isEven) {
                    if (nums[mid] == nums[mid - 1]) {
                        r = mid - 2;
                    } else {
                        return nums[mid];
                    }
                } else {
                    l = mid + 1;
                }
            }
        }
        return nums[r];
    }
};