class Solution {

    //memoization
public:
    
    bool canPartition(vector<int>& nums) {
        int sum = 0 ;
        for(int i = 0 ; i < nums.size() ; i ++){
            sum += nums[i];
        }
        if(sum %2 != 0 ) return false;
        int target = sum/2;
        int n= nums.size();
        vector<vector<int>> dp(n , vector<int>(target+1 ,0));
        for(int i = 0 ; i < n ; i ++){
            dp[i][0] = 1;
        }

        if(nums[0] <= target)dp[0][nums[0]] = 1;
        for(int i = 1 ; i < n ; i++){
            for(int j = 1; j <= target ; j++){
                bool notTaken = dp[i-1][j];
                bool taken = false;
                if(nums[i] <= j){
                    taken = dp[i-1][j-nums[i]];
                }

                dp[i][j] = taken || notTaken;
            }
        }

        return dp[n-1][target];
        
    }
};