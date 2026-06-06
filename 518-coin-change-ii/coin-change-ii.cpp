class Solution {
public:
    int change(int amount, vector<int>& coins) {

        long long n = coins.size();
        
        vector<unsigned long long> prev(amount+1 , 0 );
        prev[0] = 1;
        
            for(unsigned long long j = 1 ; j <= amount ; j++){
                if(j%coins[0] == 0) prev[j] = 1;
            }
        
        for(unsigned long long i = 1 ; i < n ; i ++){
            vector<unsigned long long> curr(amount+1 , 0);
            for(unsigned long long j = 0 ; j <= amount; j++){
                unsigned long long notTake = prev[j];
                unsigned long long Take = 0 ;
                if(coins[i] <= j) Take = curr[j-coins[i]];

                curr[j] = Take + notTake;
            }

            prev = curr;
        }

        return prev[amount];
        
    }
};