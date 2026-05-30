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
private:
stack<TreeNode*> sn ; 
stack<TreeNode*> sb; 
void BSTiterator_left(TreeNode* root){
    pushallleft(root);
}

void BSTiterator_right(TreeNode* root){
    pushallright(root);
}



void pushallleft(TreeNode* root){
    if(root == NULL) return;
    sn.push(root);
    pushallleft(root->left);
}

void pushallright(TreeNode* root){
    if(root == NULL) return;
    sb.push(root);
    pushallright(root->right);
}

int next(){
    TreeNode* node = sn.top();
    sn.pop();
    
    pushallleft(node->right);
    return node->val;
}

int before(){
    TreeNode* node = sb.top();
    sb.pop();
    pushallright(node->left);
    return node->val;
}


public:
    bool findTarget(TreeNode* root, int k) {
        BSTiterator_left(root);
        BSTiterator_right(root);

        int i = next();
        int j = before();

        while(i < j){
            if(i + j == k) return true ;
            else if(i+ j < k) i = next();
            else j = before();
        }

        return false;
    }
};

