class Solution
{
public:
    int numberOfAlternatingGroups(vector<int> &colors, int k)
    {
        int n = colors.size();
        for (int i = 0; i < k - 1; i++)
        {
            colors.push_back(colors[i]);
        }
        int i = 0, j = 1, res = 0;
        while (j < n + (k - 1))
        {
            if (colors[j] == colors[j - 1])
            {
                i = j;
            }

            if (j - i + 1 == k)
            {
                res++;
                i++;
            }
            j++;
        }
        return res;
    }
};

class Solution
{
public:
    int numberOfAlternatingGroups(vector<int> &colors, int k)
    {
        int n = colors.size();
        for (int i = 0; i < k - 1; i++)
        {
            colors.push_back(colors[i]);
        }
        int i = 1, length = 1, res = 0, lastColor = colors[0];
        while (i < n + (k - 1))
        {
            if (colors[i] == lastColor)
            {
                length = 1;
            }
            else
            {
                length++;
                lastColor = colors[i];
            }

            if (length >= k)
            {
                res++;
            }
            i++;
        }
        return res;
    }
};