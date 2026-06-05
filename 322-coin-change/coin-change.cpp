class Solution {
public:
//memoization

    int helper(int idx ,vector<int>& coins, int amount ,vector<vector<int>> &dp ){
        if(amount == 0 ){
            dp[idx][0] = 0;
            return 0;
        }

        if(idx == 0){
            if(amount%coins[0] == 0)return amount/coins[0] ;
            return -1;
        }
        if(dp[idx][amount] != -2) return dp[idx][amount];

        int Take = -1;
        
        
        if(coins[idx] <= amount){
            int a = helper(idx , coins , amount-coins[idx] , dp);
            if(a != -1) Take  = 1 + a;
        }

        int notTaken = helper(idx-1 , coins , amount , dp);
        if(Take == -1 && notTaken == -1) return dp[idx][amount] = -1;
        if(Take == -1) return dp[idx][amount] = notTaken;
        if(notTaken == -1) return dp[idx][amount] = Take;
        return dp[idx][amount] = min(Take , notTaken);
       

        
        


    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
      vector<vector<int>> dp(n, vector<int>(amount+1 , -2));
      return helper(n-1 , coins ,amount , dp);  
      
    }
};