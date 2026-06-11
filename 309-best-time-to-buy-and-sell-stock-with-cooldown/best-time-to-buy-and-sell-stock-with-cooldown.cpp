class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2 , vector<int>(2, 0));
        for(int j = n-1; j>= 0 ; j--){
            for(int buy = 0 ; buy <= 1 ;buy++){
                if(buy == 1){
                    dp[j][buy] = max(-prices[j]+dp[j+1][0] , dp[j+1][1]);
                }

                else{
                    dp[j][buy] = max(prices[j]+dp[j+2][1] , dp[j+1][0]);
                }
            }
        }

        return dp[0][1];
    }
};