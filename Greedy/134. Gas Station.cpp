class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
       int sum = 0, total = 0, starting_position = 0;
       for(int i=0; i<gas.size(); i++){
           sum += gas[i] - cost[i];
           if(sum < 0){
              total += sum;
              sum = 0;
              starting_position = i+1;
           }   
        } 
        total += sum;
        if(total>=0){
            return starting_position;
        }
        else{
            return -1;
        }
    }
};