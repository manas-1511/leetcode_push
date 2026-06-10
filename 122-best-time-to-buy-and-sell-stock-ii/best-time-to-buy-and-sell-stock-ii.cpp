class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //space optimization
        int n = prices.size();
        int prev0 = 0;
        int prev1 = 0;
        
            for(int j = n-1 ; j >= 0; j--){
                int temp0 = prev0;
                prev0 = max( prices[j] + prev1 , prev0);
                prev1 = max(-prices[j] + temp0 , prev1);

            }

            return prev1;
        


    }
};