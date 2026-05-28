/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        if( root == p ) return p ; 
        if( root == q) return q;

        TreeNode* left_ans = lowestCommonAncestor(root->left , p , q);
        TreeNode* right_ans = lowestCommonAncestor(root->right , p , q);
        if(left_ans && right_ans ) return root;
        if(left_ans == NULL) return right_ans;
        return left_ans ;
    }
};