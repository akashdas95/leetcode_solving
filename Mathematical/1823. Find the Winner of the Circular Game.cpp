class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int>q;
        for(int i=1; i<=n; i++){
            q.push(i);
        }
        int i = 0;
        while(q.size() > 1){
            for(int cnt = 1; cnt <= k-1; cnt++){
                q.push(q.front());
                q.pop();
            }
            q.pop();
        }
        return q.front();
    }
};