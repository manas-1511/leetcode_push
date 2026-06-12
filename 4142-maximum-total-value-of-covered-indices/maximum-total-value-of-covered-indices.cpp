class Solution {
    private: int n = 0;
          //taken = 1 ;
          //notTaken = 0 ;

public:
    // long long f(int i , int taken , vector<int>& nums, string& s , vector<vector<long long>>& dp){
    //     if(i>= n) return 0;
    //     if(dp[i][taken] != -1) return dp[i][taken];
    //     long long  ans = f(i+1 , 0 , nums , s , dp);
    //     if(s[i] == '1' && !taken){
    //         ans = max( ans , 1LL*nums[i] + f(i+1 , 0 , nums , s ,dp));
    //     }

    //     if(i+1 <n && s[i+1] == '1'){
    //         ans = max(ans  , 1LL*nums[i] + f(i+1 , 1 , nums , s ,dp));
    //     }

    //     return dp[i][taken] = ans;

        
    // }

//tabulation
    long long maxTotal(vector<int>& nums, string s) {
        n = nums.size();
        vector<vector<long long>> dp(n+1, vector<long long>(2 , 0));
        for(int i = n-1 ; i >= 0 ; i--){
            for(int j = 0 ; j<= 1; j++){
                long long  a = dp[i+1][0];
                long long  b = 0 ;
                if(s[i] == '1' && j==0){
                    b = 1LL*nums[i] + dp[i+1][0];
                }
                long long c = 0 ;
                if(i+1 < n && s[i+1] == '1'){
                    c =  1LL*nums[i] + dp[i+1][1];
                }

                dp[i][j] = max(a ,max(b ,c));
                
            }
        }

        return dp[0][0];
    }
};