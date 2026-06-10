class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> after(n+1 , 0 );
        for(int i = n-1 ; i>= 0 ; i --){
            vector<int> curr(n+1 , 0 );
            for(int j = 0 ; j < n ; j++){
                if(j%3 == 0){
                    //buy
                    curr[j] = max(-prices[i] + after[j+1] , after[j]);
                }


                else if(j%3 == 1){
                    //sell
                    curr[j] = max(+prices[i] + after[j+1] , after[j]);
                }

                else{
                    //cooldown
                    curr[j] = after[j+1];
                }
            } 

            after = curr;


            
        }

        return after[0];
    }
};