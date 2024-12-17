//using maxHeap and minHeap
class Solution {
public:
    typedef pair<int, int>p;
    int longestSubarray(vector<int>& nums, int limit) {
        priority_queue<p,vector<p>>maxPq;
        priority_queue<p,vector<p>,greater<p>>minPq;

        int i=0,j=0;
        int maxLength = 0;
        while(j<nums.size()){
            maxPq.push({nums[j],j});
            minPq.push({nums[j],j});

            while(maxPq.top().first - minPq.top().first > limit){
                i = min(maxPq.top().second , minPq.top().second) +1;
                while(maxPq.top().second < i){
                    maxPq.pop();
                }
                while(minPq.top().second < i){
                    minPq.pop();
                }
            }
            maxLength = max(maxLength, j-i+1);
            j++;
        }

        return maxLength;
    }
};

//optimum using multiset
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int>st;
        int i=0,j=0;
        int maxLength = 0;
        while(j<nums.size()){
            st.insert(nums[j]);

            while(*st.rbegin() - *st.begin() > limit){
                st.erase(st.find(nums[i]));
                i++;
            }
            maxLength = max(maxLength, j-i+1);
            j++;
        }

        return maxLength;
    }
};