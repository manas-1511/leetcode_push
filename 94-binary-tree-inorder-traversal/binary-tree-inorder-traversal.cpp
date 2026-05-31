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

 //MORRIS traversal attempt2
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == NULL) return{};
        vector<int> ans ;
        TreeNode* curr = root;
        while(curr != NULL){


            
            if(curr->left){
                TreeNode* rightmost = curr->left;
                while(rightmost->right != NULL && rightmost->right != curr ){
                    rightmost = rightmost->right;
                }

                if(rightmost->right == NULL){
                    rightmost->right = curr;
                    curr = curr->left;
                    continue;
                }

                else{
                    ans.push_back(curr->val);
                    curr = curr->right;
                    rightmost->right = NULL;
                    continue;
                }
            }

            else{
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }

        return ans;
    }
};