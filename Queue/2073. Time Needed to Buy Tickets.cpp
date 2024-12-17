class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int ans = 0;
        for (int i = 0; i < tickets.size(); i++) {
            if (i <= k) {
                ans += min(tickets[i], tickets[k]) ;
            } else {
                ans += min(tickets[i],tickets[k]-1) ;
            }
        }
        return ans;
    }
};


//using javaScript
/**
 * @param {number[]} tickets
 * @param {number} k
 * @return {number}
 */
var timeRequiredToBuy = function(tickets, k) {
    var ans = 0;
    for(var i=0; i<tickets.length; i++){
        if(i<=k){
            ans += Math.min(tickets[i], tickets[k]);
        }
        else{
            ans += Math.min(tickets[i], tickets[k]-1);
        }
    }
    return ans;
};