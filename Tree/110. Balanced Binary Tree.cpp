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
    bool isBalanced(TreeNode* root) {
        return heightBalance(root) !=-1;
    }
    int heightBalance(TreeNode *root){
        if(!root){
            return 0;
        }
        int leftHeight = heightBalance(root->left);
        if(leftHeight==-1){
            return -1;
        }
        int rightHeight = heightBalance(root->right);
        if(rightHeight== -1){
            return -1;
        }
        if(abs(leftHeight-rightHeight)>1){
            return -1;
        }
        return 1+ max(leftHeight,rightHeight);
    }
};