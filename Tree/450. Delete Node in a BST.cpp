//connecting left child to right child's last left child
class Solution {
public:
    TreeNode* helper(TreeNode* root){
        if(!root->left){
            return root->right;
        }
        else if(!root->right){
            return root->left;
        }
        TreeNode* leftChild = root->left;
        TreeNode* lastChildFromRight = findLastChildFromLeftChild(root->right);
        lastChildFromRight->left = leftChild;
        return root->right;

    }

    TreeNode* findLastChildFromLeftChild(TreeNode* root){
        if(!root->left){
            return root;
        }
        return findLastChildFromLeftChild(root->left);
    }


    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root){
            return NULL;
        }
        if(root->val == key){
            return helper(root);
        }
        TreeNode* temp = root;
        while(root){
            if(root->val > key){
                if(root->left && root->left->val == key){
                    root->left = helper(root->left);
                    break;
                }
                else{
                    root = root ->left;
                }
            }
            else{
                if(root->right && root->right->val == key){
                    root->right = helper(root->right);
                    break;
                }
                else{
                    root = root->right;
                }
            }
        }
        return temp;
    }
};


//connecting right child to left child's last right child
class Solution {
public:
    TreeNode* helper(TreeNode* root){
        if(!root->left){
            return root->right;
        }
        else if(!root->right){
            return root->left;
        }
        TreeNode* rightChild = root->right;
        TreeNode* lastChildFromLeft = findLastChildFromLeftChild(root->left);
        lastChildFromLeft->right = rightChild;
        return root->left;

    }

    TreeNode* findLastChildFromLeftChild(TreeNode* root){
        if(!root->right){
            return root;
        }
        return findLastChildFromLeftChild(root->right);
    }


    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root){
            return NULL;
        }
        if(root->val == key){
            return helper(root);
        }
        TreeNode* temp = root;
        while(root){
            if(root->val > key){
                if(root->left && root->left->val == key){
                    root->left = helper(root->left);
                    break;
                }
                else{
                    root = root ->left;
                }
            }
            else{
                if(root->right && root->right->val == key){
                    root->right = helper(root->right);
                    break;
                }
                else{
                    root = root->right;
                }
            }
        }
        return temp;
    }
};