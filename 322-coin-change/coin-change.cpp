class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> prev(amount+1 , -1);
        prev[0] = 0;
        for(int j = 1 ; j <= amount ; j ++){
            if(j%coins[0] == 0) prev[j] = j/coins[0];
        }
        int n = coins.size();

        for(int i = 1 ; i < n ; i ++){
            vector<int> curr(amount+1 , -1);
            curr[0] = 0;
            for(int j = 1 ; j <= amount ; j ++){
                int no = prev[j];
                int taken = -1;
                if(coins[i] <= j){
                    int a = curr[j-coins[i]];
                    if( a != -1) taken = a +1;
                }

                if(no == -1 && taken == -1) curr[j] = -1;
                else if(no == -1) curr[j] = taken;
                else if(taken == -1) curr[j] = no;
                else curr[j] = min(no , taken);
            }

            prev = curr;
        }

        return prev[amount];

    }
};