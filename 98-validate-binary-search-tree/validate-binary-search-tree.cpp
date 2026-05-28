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
    TreeNode* getleftmost(TreeNode* root){
        if(root== NULL) return NULL;
        if(root->left == NULL) return root;
        return getleftmost(root->left);

    }

    TreeNode* getrightmost(TreeNode* root){
        if(root== NULL) return NULL;
        if(root->right == NULL) return root;
        return getrightmost(root->right);
    }

    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        TreeNode* rightsubtree = getleftmost(root->right);
        TreeNode* leftsubtree = getrightmost(root->left);
        bool r = false ;
        bool l = false ;

        if(rightsubtree == NULL) r = true ;
        else{
            if(rightsubtree->val > root->val)r = true;
        }
        if(leftsubtree == NULL) l = true;
        else{
            if(leftsubtree->val < root->val) l = true;

        }

        bool a = isValidBST(root->left);
        bool b = isValidBST(root->right);

        return r && l && a && b;



    }
};