class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int after0 = 0 ; 
        int after1 = 0;
        for(int j = n-1 ; j>= 0 ; j--){
            int temp1 = after1;
            after1 = max(-prices[j] + after0 , after1);
            after0 = max(prices[j]+temp1-fee , after0);
        }

        return after1;
    }
};