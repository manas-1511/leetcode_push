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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int , TreeNode*> mp ; 
        unordered_map<int , int> root;


        for(auto it : descriptions){
            int parent = it[0] , child = it[1] , isLeft = it[2];

            if(mp.find(parent) == mp.end()){
                TreeNode* Parent  = new TreeNode(parent);
                mp[parent] = Parent;
            }

            if(mp.find(child) == mp.end()){
                TreeNode* Child = new TreeNode(child);
                mp[child] = Child;
            }

            if(isLeft) mp[parent]->left = mp[child];
            else mp[parent]->right = mp[child];

            if(root[parent] != -1){
                root[parent] = 1;
            }

            root[child] = -1;


        }

        int value = 0 ;
        for(auto it : root){
            if(it.second == 1){
                value = it.first;
                break;
            }
        }

        return mp[value];

    }
};