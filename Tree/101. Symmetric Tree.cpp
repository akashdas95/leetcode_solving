/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool symmetric(TreeNode* leftNode, TreeNode* rightNode) {
        if (!leftNode || !rightNode) {
            return leftNode == rightNode;
        }
        if (leftNode->val != rightNode->val) {
            return false;
        }
        return symmetric(leftNode->left, rightNode->right) &&
               symmetric(leftNode->right, rightNode->left);
    }
    bool isSymmetric(TreeNode* root) {
        return !root || symmetric(root->left, root->right);
    }
};