class Solution {
public:
//brute force 
    //tC : n! * n 
    //SC: O(n) + O(n) one is for map and the other for the curr array to be stored
    void helper(vector<int>& nums , vector<int>& curr , vector<int>& visited  ,vector<vector<int>>& ans ){
        if(curr.size() == nums.size()){
            ans.push_back(curr);
        }
        int n = nums.size();

        for(int i = 0 ; i < n ; i ++){
            if(!visited[i]){
                visited[i] = 1;
                curr.push_back(nums[i]);
                helper(nums , curr , visited , ans );
                visited[i] = 0; 
                curr.pop_back();
            }
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
         vector<vector<int>> ans ; 
        vector<int> curr;
        vector<int> visited(nums.size() , false);
        helper(nums , curr , visited  ,ans);
        return ans;
    }
};