class Solution {

    //memoization
public:
    bool helper(int idx , vector<int>& nums , int target , vector<vector<int>>& dp){
        if(dp[idx][target] != -1) return dp[idx][target];
        if(idx== 0 ){
            return dp[0][target] = (nums[0] == target);
        }
        if(target == 0 ){
            return dp[idx][target] = 1;

        }
        bool notTaken = helper(idx-1 , nums ,target , dp);
        bool taken = false;
        if(nums[idx] <= target){
            taken = helper(idx-1 , nums , target-nums[idx] , dp);
        }

        return dp[idx][target] = taken || notTaken ; 
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0 ;
        for(int i = 0 ; i < nums.size() ; i ++){
            sum += nums[i];
        }
        if(sum %2 != 0 ) return false;
        int target = sum/2;
        int n= nums.size();
        vector<vector<int>> dp(n , vector<int>(target+1 ,-1));

        helper(n-1 , nums , target , dp);

        return dp[n-1][target];
    }
};