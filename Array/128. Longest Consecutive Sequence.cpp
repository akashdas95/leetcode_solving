class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        int ans = 0;

        for(int i=0; i<nums.size();i++){
            st.insert(nums[i]);
        }

        for(auto it: st){
            if(st.find(it-1)==st.end()){
                int cnt=1;
                int x= it;
                while(st.find(x+1)!= st.end()){
                    cnt++;
                    x++;
                }

                ans= max(ans,cnt);
            }
        }
        return ans;
    }
};