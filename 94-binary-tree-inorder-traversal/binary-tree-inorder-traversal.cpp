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

 //MORRIS traversal
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int > inorder;
        TreeNode* curr = root;
        while(curr != NULL){
            if(curr->left == NULL){
                inorder.push_back(curr->val);
                curr = curr->right;
            }

            else{
                TreeNode* prev = curr->left;
                while(prev->right != NULL && prev->right != curr){
                    prev = prev->right;
                }

                if(prev->right == NULL){
                    prev->right = curr;
                    curr = curr->left;
                }

                else{
                    //that means i have already traversed the left sub-tree so i have to break the connection to the root and move toward the right of the root and also just push_back the curr 
                    prev->right = NULL;
                    inorder.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }

        return inorder;
    }
};