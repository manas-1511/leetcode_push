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

class NodeValue {
    public:
    int maxNode ,minNode , sum;
    NodeValue(int maxNode , int minNode ,int  sum){
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->sum = sum;
    }
};

class Solution {
public:
    int ans = 0 ;
    NodeValue helper(TreeNode* root){
        if(root == NULL) 
        return NodeValue(INT_MIN , INT_MAX , 0);

        auto left = helper(root->left);
        auto right = helper(root->right);
        //its BST
        if(left.maxNode < root->val && right.minNode > root->val){
            int currSum = left.sum + right.sum + root->val;
            ans = max(ans , currSum);
            return NodeValue(max(root->val , right.maxNode) , min(root->val , left.minNode) , currSum) ; 
        }

            return NodeValue(INT_MAX , INT_MIN , 0);
       




    }
    int maxSumBST(TreeNode* root) {
        
        helper(root);
        return ans;
    }
};