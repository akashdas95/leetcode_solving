//c++
class Solution {
public:
    
    int dfs(TreeNode* root, int maxVal){
        if(!root){
            return 0;
        }
        int count = 0;
        if(root->val >= maxVal){
            count++;
        }
        count += dfs(root->left, max(root->val,maxVal));
        count += dfs(root->right, max(root->val,maxVal));
        return count;
    }
    int goodNodes(TreeNode* root) {
       return dfs(root,root->val);
    }
};



//java
class Solution {
    int dfs(TreeNode root, int maxVal) {
        if (root == null) {
            return 0;
        }
        int count = 0;
        if (root.val >= maxVal) {
            count++;
        }
        count += dfs(root.left, Math.max(root.val, maxVal));
        count += dfs(root.right, Math.max(root.val, maxVal));
        return count;
    }

    public int goodNodes(TreeNode root) {
        return dfs(root, root.val);
    }
}