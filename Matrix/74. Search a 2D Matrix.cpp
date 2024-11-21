class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0){
            return false;
        }
        int m= matrix.size();
        int n = matrix[0].size();
        int l=0, r=(n*m)-1;
        
        while(l<=r){
            int mid= l+(r-l)/2;
            int row = mid/n, col = mid%n;
            if(matrix[row][col]==target){
                return true;
            }
            else if(matrix[row][col]<target){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return false;
    }
};