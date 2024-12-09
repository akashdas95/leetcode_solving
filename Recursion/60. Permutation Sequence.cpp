class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int>v;
        int factorial = 1;
        string ans ="";
        for(int i=1; i<n; i++){
            v.push_back(i);
            factorial = factorial * i;
        }
        v.push_back(n);
        k = k -1;
        while(true){
            ans = ans + to_string(v[k/factorial]);
            v.erase(v.begin()+ k/factorial);
            if(v.size()==0){
                break;
            }
            k = k % factorial;
            factorial = factorial / v.size();
        }
        return ans;

    }
};