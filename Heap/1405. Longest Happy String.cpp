class Solution {
public:
    typedef pair<int,char>p;
    string longestDiverseString(int a, int b, int c) {
        priority_queue<p,vector<p>>pq;

        if(a>0){
            pq.push({a,'a'});
        }
        if(b>0){
            pq.push({b,'b'});
        }
        if(c>0){
            pq.push({c,'c'});
        }
        string res = "";

        while(!pq.empty()){
            int currCount = pq.top().first;
            char currChar = pq.top().second;
            pq.pop();
            if(res.length()>=2 && currChar == res[res.length()-1] && currChar == res[res.length()-2]){
                if(pq.empty()){
                    break;
                }
                int nextCount = pq.top().first;
                char nextChar = pq.top().second;
                pq.pop();
                res.push_back(nextChar);
                nextCount--;
                if(nextCount>0){
                    pq.push({nextCount, nextChar});
                }
            }
            else{
                currCount--;
                res.push_back(currChar);
            }

            if(currCount>0){
                pq.push({currCount,currChar});
            }
        }
        return res;
    }
};