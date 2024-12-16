class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int n = heights.size();
        int leftsmall[n], rightsmall[n];
 
        //for creating leftsmall NGE array
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>= heights[i]){
                st.pop();
            }
            if(st.empty()){
                leftsmall[i] = 0;
            }
            else{
                leftsmall[i] = st.top()+1;
            }
            st.push(i);
        }

        //clearing the stack for reusing
        while(!st.empty()){
            st.pop();
        }

        //for creating rightsmall NGE array
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>= heights[i]){
                st.pop();
            }
            if(st.empty()){
                rightsmall[i] = n-1;
            }
            else{
                rightsmall[i] = st.top()-1;
            }
            st.push(i);
        }
         
        //compute the largest histogram
        int largest_his = 0;
        for(int i=0; i<n; i++){
           largest_his = max(largest_his, (rightsmall[i]-leftsmall[i]+1)* heights[i]);
        }
        return largest_his; 
    }
};