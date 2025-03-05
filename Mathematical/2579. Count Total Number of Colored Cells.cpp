// Brute Force(O(n))
class Solution
{
public:
    long long coloredCells(int n)
    {
        int t = 1;
        long long cells = 1;
        while (t <= n)
        {
            cells += (4 * (t - 1));
            t++;
        }
        return cells;
    }
};

// optimize by math(O(1))
class Solution
{
public:
    long long coloredCells(int n) { return 1 + (2 * (long long)(n - 1) * n); }
};