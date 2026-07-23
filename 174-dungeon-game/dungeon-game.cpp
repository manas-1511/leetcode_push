class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<long long>> dp(m+1 , vector<long long>( n+1 , INT_MIN));
        for(int i = m-1 ; i>=0 ;i--){
            for(int j = n-1 ; j >= 0 ; j--){
                long long a;
                if(dp[i+1][j] == INT_MIN && dp[i][j+1] == INT_MIN) a=dungeon[i][j];
                else a = dungeon[i][j] + max(dp[i+1][j] , dp[i][j+1]);
                if(a>=0) dp[i][j] = 0;
                else dp[i][j] = a;
            }
        }

        return -1*(int)dp[0][0]+1;
    }
};