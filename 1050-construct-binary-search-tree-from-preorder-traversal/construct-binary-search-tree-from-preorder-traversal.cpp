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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size() == 0 ) return NULL;
        TreeNode* root = new TreeNode(preorder[0]);
        if(preorder.size() == 1){
            
            return root;
        }

        int leftindex = -1;
        int rightindex = -1;
        if(preorder[0] > preorder[1]) leftindex = 1;

        for(int i = 1 ; i < preorder.size() ; i ++){
            if(preorder[0] < preorder[i]) {
                rightindex = i;
                break;
            }
        }
        vector<int> leftv;
        vector<int> rightv;
        if(leftindex != -1){
            if(rightindex == -1){
                leftv =  vector<int>(preorder.begin() +1 , preorder.end());
                
            }
            else{
                leftv = vector<int>(preorder.begin() +1 , preorder.begin() + rightindex);
            }
            
        }

        if(rightindex != -1){
            rightv = vector<int>(preorder.begin() +rightindex  , preorder.end());
            
        }

        TreeNode* leftsub = bstFromPreorder(leftv);
        TreeNode* rightsub = bstFromPreorder(rightv);
        root->left = leftsub;
        root->right = rightsub;
        return root;
        
        




    
        
    }
};