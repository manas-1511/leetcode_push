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
    void traversal(TreeNode* root , vector<TreeNode*> &v){
        if( root == NULL) return;
        traversal(root->left , v);
        v.push_back(root);
        traversal(root->right , v);
    }
    void recoverTree(TreeNode* root) {
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL) return;
         vector<TreeNode*> v ;
        traversal(root , v);
        TreeNode* first = NULL;
        TreeNode* middle = NULL;
        TreeNode* last = NULL;
        for(int i = 1 ; i < v.size() ; i ++){
            if(v[i]->val <= v[i-1]->val){
                if(first == NULL) {
                    first = v[i-1];
                    middle = v[i];
                }

                else last = v[i];
            }
        }

        if(last == NULL){
            int temp = first->val;
            first->val = middle->val;
            middle->val = temp;
        }

        else{
            int temp = first->val;
            first->val = last->val;
            last->val = temp;
        }

        return ;


    }
};