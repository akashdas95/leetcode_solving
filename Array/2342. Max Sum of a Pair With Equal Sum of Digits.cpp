// C++ Brute force
class Solution
{
public:
    int digitSum(int digit)
    {
        int sum = 0;
        while (digit > 0)
        {
            sum += digit % 10;
            digit = digit / 10;
        }
        return sum;
    }

    int maximumSum(vector<int> &nums)
    {
        int res = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            int digitSumofI = digitSum(nums[i]);
            for (int j = i + 1; j < nums.size(); j++)
            {
                int digitSumofJ = digitSum(nums[j]);
                if (digitSumofI == digitSumofJ)
                {
                    res = max(res, nums[i] + nums[j]);
                }
            }
        }
        return res;
    }
};

// C++ better
class Solution
{
public:
    int getDigitSum(int digit)
    {
        int sum = 0;
        while (digit > 0)
        {
            sum += digit % 10;
            digit = digit / 10;
        }
        return sum;
    }

    int maximumSum(vector<int> &nums)
    {
        int res = -1;
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            int digitSum = getDigitSum(nums[i]);

            if (mp.count(digitSum))
            {
                res = max(res, nums[i] + mp[digitSum]);
            }

            mp[digitSum] = max(nums[i], mp[digitSum]);
        }
        return res;
    }
};


//Java Better
class Solution {
    public int getDigitSum(int digit) {
        int sum = 0;
        while (digit > 0) {
            sum += digit % 10;
            digit = digit / 10;
        }
        return sum;
    }

    public int maximumSum(int[] nums) {
        int res = -1;
        Map<Integer, Integer> mp = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            int digitSum = getDigitSum(nums[i]);

            if (mp.containsKey(digitSum)) {
                res = Math.max(res, nums[i] + mp.get(digitSum));
            }

            mp.put(digitSum, Math.max(nums[i], mp.getOrDefault(digitSum,-1)));
        }
        return res;
    }
}
