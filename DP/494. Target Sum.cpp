//Brute Force
class Solution {
public:
    int solve(vector<int>& nums, int idx, int currSum, int target) {
        if (idx == nums.size()) {
            if (currSum == target) {
                return 1;
            } else {
                return 0;
            }
        }
        int plusSum = solve(nums, idx + 1, currSum + nums[idx], target);
        int minusSum = solve(nums, idx + 1, currSum - nums[idx], target);
        return plusSum + minusSum;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums, 0, 0, target);
    }
};

//using memoization with the help of unordered map
class Solution {
public:
    int solve(vector<int>& nums, int idx, int currSum, int target, unordered_map<string, int>&mp) {
        if (idx == nums.size()) {
            if (currSum == target) {
                return 1;
            } else {
                return 0;
            }
        }
        string key = to_string(idx) + "_" + to_string(currSum);
        if(mp.count(key)){
            return mp[key];
        }
        int plusSum = solve(nums, idx + 1, currSum + nums[idx], target, mp);
        int minusSum = solve(nums, idx + 1, currSum - nums[idx], target, mp);
        return mp[key] = plusSum + minusSum;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<string, int>mp;
        return solve(nums, 0, 0, target, mp);
    }
};

//using memoization with the help of 2D vector
class Solution {
public:
    int S;
    int solve(vector<int>& nums, int idx, int currSum, int target, vector<vector<int>>& t) {
        if (idx == nums.size()) {
            if (currSum == target) {
                return 1;
            } else {
                return 0;
            }
        }

        if (t[idx][currSum + S] != -1) {
            return t[idx][currSum + S];
        }

        int plusSum = solve(nums, idx + 1, currSum + nums[idx], target, t);
        int minusSum = solve(nums, idx + 1, currSum - nums[idx], target, t);
        return t[idx][currSum + S] = plusSum + minusSum;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        S = accumulate(begin(nums), end(nums), 0);
        vector<vector<int>> t(nums.size() + 1, vector<int>(2 * S + 1, -1));
        return solve(nums, 0, 0, target, t);
    }
};