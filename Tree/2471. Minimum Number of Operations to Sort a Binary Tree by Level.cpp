/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minSwapToSort(vector<int>&vec){
        int count = 0;
        vector<int>sortedVec(begin(vec),end(vec));
        sort(begin(sortedVec),end(sortedVec));
        unordered_map<int, int>mp;
        for(int i=0; i<vec.size(); i++){
            mp[vec[i]] = i;
        }
        for(int i=0; i<vec.size(); i++){
            if(vec[i] == sortedVec[i]){
                continue;
            }
            int currIndex = mp[sortedVec[i]];
            mp[vec[i]] = currIndex;
            swap(vec[i], vec[currIndex]);
            count++;
        }
        return count;
    }
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*>que;
        que.push(root);
        int res = 0;
        while(!que.empty()){
            int n = que.size();
            vector<int>vec;
            while(n--){
                TreeNode* node = que.front();
                que.pop();
                vec.push_back(node->val);
                if(node->left){
                    que.push(node->left);
                }
                if(node->right){
                    que.push(node->right);
                }
            }
            res += minSwapToSort(vec);
        }
        return res;
    }
};