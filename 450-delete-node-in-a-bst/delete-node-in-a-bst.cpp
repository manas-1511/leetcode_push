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

    TreeNode* helper(TreeNode* root){
        if(root->right == NULL) return root->left;
        if(root->left == NULL) return root->right;

        TreeNode* rightmost = (root->left);
        while(rightmost->right != NULL ) rightmost = rightmost->right;
        rightmost->right = root->right;

        return root->left;
    }
        // 2nd Attempt after 3 days
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;
        if(root->val == key){
            return helper(root);
        }

        TreeNode* dummy = root;
        while(root != NULL){
            if(root->val > key){
                if(root->left && root->left->val == key){
                    root->left = helper(root->left);
                    break;
                }

                else root =root->left;
            }

            else{
                if(root->right && root->right->val == key){
                    root->right = helper(root->right);

                    break;
                }

                else root = root->right;
            }
    }

    return dummy;
    }
};