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

    TreeNode* findRightMost(TreeNode* root){
        if(root->right == NULL) return root;
        return findRightMost(root->right);

    }


    TreeNode* helper(TreeNode* root){
        if(root->right == NULL) return root->left;
        if(root->left == NULL) return root->right;

        TreeNode* rightChild = root->right;
        TreeNode* rightMost = findRightMost(root->left);
        rightMost->right = rightChild;

        return root->left;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        //for root
        if(root == NULL ) return NULL;
        if(root->val == key) return helper(root);
        TreeNode* dummy = root;
        while(root!= NULL){

            //for left traversal
            if(root->val > key){
                if(root->left != NULL && root->left->val == key){
                    root->left = helper(root->left);
                    break ;
                }

                else root = root->left;
            }


            //for the right traversal
            else{
                if(root->right != NULL && root->right->val == key){
                    root->right = helper(root->right);
                    break;

                }

                else root = root->right;
            }

        }
        //no else if for returning the dummmy
        return dummy;


                
    }
};