class Solution {
public:
    int trap(vector<int>& height) {
        int LHeight = 0;
        int RHeight = 0;
        int LSideHeight[height.size()+1];
        int RSideHeight[height.size()+1];
        for(int i=0; i<height.size(); i++){
            LHeight= max(LHeight,height[i]);
            LSideHeight[i]= LHeight;
        }
        for(int i=height.size()-1; i>=0; i--){
            RHeight= max(RHeight,height[i]);
            RSideHeight[i]= RHeight;
        }
        int cumulative_height, total_height=0;
        for(int i=0; i<height.size(); i++){
           cumulative_height = min(LSideHeight[i],RSideHeight[i])-height[i];
           total_height += cumulative_height;
        }
        return total_height;
    }
};