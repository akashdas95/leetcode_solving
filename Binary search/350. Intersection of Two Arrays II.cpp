class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int>mp;
        for(int &num : nums1){
            mp[num]++;
        }

        vector<int>res;
        for(int i =0; i<nums2.size(); i++){
            if(mp[nums2[i]] > 0){
                res.push_back(nums2[i]);
                mp[nums2[i]]--;
            }
        }
        return res;  
    }
};