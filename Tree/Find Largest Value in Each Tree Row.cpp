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
    int largestValByRow(vector<int>&vec){
        int mxVal = vec[0];
        for(int i=0; i<vec.size(); i++){
            if(vec[i] > mxVal){
                mxVal = vec[i];
            }
        }
        return mxVal;
    }

    vector<int> largestValues(TreeNode* root) {
        if(root == NULL){
            return {};
        }
        vector<int>res;
        queue<TreeNode*>que;
        que.push(root);
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
            int largestVal = largestValByRow(vec);
            res.push_back(largestVal);
        }
        return res;
    }
};