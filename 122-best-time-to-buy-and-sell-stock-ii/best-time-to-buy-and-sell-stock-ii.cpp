class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(2 , vector<int>(n+1,0));
        
            for(int j = n-1 ; j >= 0; j--){
                dp[0][j] = max( prices[j] + dp[1][j+1] , dp[0][j+1]);
                dp[1][j] = max(-prices[j] + dp[0][j+1] , dp[1][j+1]);

            }

            return dp[1][0];
        


    }
};