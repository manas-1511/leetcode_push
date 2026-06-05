class Solution {
public:
//memoization

    // int helper(int idx ,vector<int>& coins, int amount ,vector<vector<int>> &dp ){
    //     if(amount == 0 ){
    //         dp[idx][0] = 0;
    //         return 0;
    //     }

    //     if(idx == 0){
    //         if(amount%coins[0] == 0)return amount/coins[0] ;
    //         return -1;
    //     }
    //     if(dp[idx][amount] != -2) return dp[idx][amount];

    //     int Take = -1;
        
        
    //     if(coins[idx] <= amount){
    //         int a = helper(idx , coins , amount-coins[idx] , dp);
    //         if(a != -1) Take  = 1 + a;
    //     }

    //     int notTaken = helper(idx-1 , coins , amount , dp);
    //     if(Take == -1 && notTaken == -1) return dp[idx][amount] = -1;
    //     if(Take == -1) return dp[idx][amount] = notTaken;
    //     if(notTaken == -1) return dp[idx][amount] = Take;
    //     return dp[idx][amount] = min(Take , notTaken);
       

        
        


    // }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
      vector<vector<int>> dp(n, vector<int>(amount+1 , -1));
      for(int i = 0 ; i < n ; i ++){
        dp[i][0] = 0;
      }

      for(int j = 1 ; j <= amount ; j++){
        if(j%coins[0] == 0) dp[0][j] = j/coins[0];
      }


      for(int i = 1; i <n ; i ++){
        for(int j = 1; j <= amount ; j++){
            int notTaken = dp[i-1][j];
            int Taken = -1;
            if(coins[i] <= j ){
                int a = dp[i][j-coins[i]] ;
                if( a != -1) Taken = 1+a;
            }

            if(Taken == -1 && notTaken == -1) dp[i][j] = -1;
            else if(Taken == -1) dp[i][j] = notTaken;
            else if(notTaken == -1) dp[i][j] = Taken;
            else dp[i][j] = min(Taken , notTaken);
        }
      }

      return dp[n-1][amount];
        
        
      
      
    }
};