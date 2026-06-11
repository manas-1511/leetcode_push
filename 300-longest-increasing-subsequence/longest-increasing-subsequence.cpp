class Solution {
public:
//Tabulation

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1 , vector<int>(n+1 , 0));
        //coulmns are from -1 to n-1 (prev_index)
        //rows = 0 to n (0 based index) but nth row just to maintain the edge values
        //pi = prev_idx

        for(int i = n-1 ; i>= 0 ; i--){
            for(int pi = i-1 ; pi>=-1 ; pi--){
                //index = i+1 , prev_index = same pi
                //because -1 is 0th column in dp therefore dp[x][pi+1] represents it
                int notTake = dp[i+1][pi+1];

                int Take = 0;
                if(pi == -1 || nums[pi] < nums[i]) Take = 1+dp[i+1][i+1];
                dp[i][pi+1] = max(notTake , Take);

            }
        }

        return dp[0][-1+1];
    }
};