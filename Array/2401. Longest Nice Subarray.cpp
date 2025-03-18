class Solution
{
public:
    int longestNiceSubarray(vector<int> &nums)
    {
        int res = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int mask = 0;
            for (int j = i; j < nums.size(); j++)
            {
                if ((mask & nums[j]) != 0)
                {
                    break;
                }
                mask |= nums[j];
                res = max(res, j - i + 1);
            }
        }
        return res;
    }
};

class Solution
{
public:
    int longestNiceSubarray(vector<int> &nums)
    {
        int res = 0;
        int i = 0, j = 0;
        int mask = 0;
        while (j < nums.size())
        {
            while ((mask & nums[j]) != 0)
            {
                mask ^= nums[i];
                i++;
            }
            mask |= nums[j];
            res = max(res, j - i + 1);
            j++;
        }
        return res;
    }
};