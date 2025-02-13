// C++
class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        priority_queue<long, vector<long>, greater<long>> pq(begin(nums), end(nums));

        int count = 0;
        while (!pq.empty() && pq.top() < k)
        {
            long x = pq.top();
            pq.pop();
            long y = pq.top();
            pq.pop();
            long val = (min(x, y) * 2) + max(x, y);
            pq.push(val);
            count++;
        }
        return count;
    }
};

// Java
class Solution
{
public
    int minOperations(int[] nums, int k)
    {
        PriorityQueue<Long> minHeap = new PriorityQueue<Long>();
        for (int i = 0; i < nums.length; i++)
        {
            minHeap.add((long)nums[i]);
        }

        int count = 0;
        while (!minHeap.isEmpty() && minHeap.peek() < k)
        {
            long x = minHeap.remove();
            long y = minHeap.remove();
            long val = (Math.min(x, y) * 2) + Math.max(x, y);
            minHeap.add((long)val);
            count++;
        }
        return count;
    }
}
