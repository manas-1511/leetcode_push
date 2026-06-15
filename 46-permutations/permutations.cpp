class Solution {
public:
//optimized approach 


//TC:n!*n because for every step iam iterating all the idices to the right of the current pointer and there are n! combinations
//SC: o(1) if recursion stack spaces are ignored 

    void helper(int idx  , vector<vector<int>> &ans , vector<int>& nums){
        if(idx== nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i = idx ; i  <nums.size() ; i ++ ){
            swap(nums[idx] ,nums[i] );
            helper(idx+1 , ans , nums);
            swap(nums[idx] , nums[i]);
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>curr;
        helper( 0  , ans  , nums);
        return ans;
    }
};