class RecentCounter {
public:
    queue<int>q;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        if(q.size() == 0){
            q.push(t);
            return 1;
        }
        else{
            if(t <= 3000){
                q.push(t);
            }
            else{
                int window = t - 3000;
                while(q.size() && q.front() < window){
                    q.pop();
                }
                q.push(t);
            }
            return q.size();
        }
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */