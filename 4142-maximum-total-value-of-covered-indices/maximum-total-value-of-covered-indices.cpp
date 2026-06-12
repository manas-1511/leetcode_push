class Solution {
    private: int n = 0;
            
public:
    long long f(int i , int taken , vector<int>& nums, string& s , vector<vector<long long>>& dp){
        if(i>= n) return 0;
        if(dp[i][taken] != -1) return dp[i][taken];
        long long  ans = f(i+1 , 0 , nums , s , dp);
        if(s[i] == '1' && !taken){
            ans = max( ans , 1LL*nums[i] + f(i+1 , 0 , nums , s ,dp));
        }

        if(i+1 <n && s[i+1] == '1'){
            ans = max(ans  , 1LL*nums[i] + f(i+1 , 1 , nums , s ,dp));
        }

        return dp[i][taken] = ans;

        
    }


    long long maxTotal(vector<int>& nums, string s) {
        n = nums.size();
        vector<vector<long long>> dp(n , vector<long long>(2 , -1));
        return f(0 , 0 , nums , s , dp);
    }
};