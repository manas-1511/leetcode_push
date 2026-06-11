class Solution {
public:
//Tabulation

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1 , vector<int>(n+1 , 0));
        //coulmns are from -1 to n-1 (prev_index)
        //rows = 0 to n (1 based index)
        for(int i = 1 ; i<= n ; i++){
            dp[i][0] = 1;
        }

        for(int i =1 ; i <= n; i++){
            for(int j = 0 ; j <= n ; j++){
                
                    //prev_index = -1
                    int notTake = dp[i-1][j];
                    int Take = 0 ;
                     if(j==0 || nums[i-1] < nums[j-1]) Take = 1+dp[i-1][i];
                    dp[i][j] = max(Take , notTake);
                





            }
            
        }

        int ans = INT_MIN;
        for(int i = 0 ; i <= n ; i++){
            ans = max(ans , dp[n][i]);
        }

        return ans;
    }
};