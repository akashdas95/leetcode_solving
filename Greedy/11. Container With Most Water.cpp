class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0, r=height.size()-1;
        int container = 0, max_container = 0;
        while(l<r){
          if(height[l]<height[r]){
            container = height[l]* (r-l);
            l++;
          }
          else{
            container = height[r]* (r-l);
            r--;
          }
          max_container = max(max_container,container);
        }
        return max_container;
    }
};