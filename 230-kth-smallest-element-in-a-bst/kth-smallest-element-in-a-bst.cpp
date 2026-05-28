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
    void helper(TreeNode* root , stack<int>& st){
        if(root == NULL) return;

        helper(root->right , st);
        st.push(root->val);
        helper(root->left , st);

        
    }
    int kthSmallest(TreeNode* root, int k) {
        
        stack<int> st;
        helper(root , st );
       
        for(int i = 0 ; i < k-1 ; i++){
            st.pop();
        }

        return st.top();
    }
};