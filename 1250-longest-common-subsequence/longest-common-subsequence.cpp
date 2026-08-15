class Solution {
public:
    int longestCommonSubsequence(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<vector<int>> dp( m+1 , vector<int>(n+1));
        for(int i = 0 ; i < m; i ++){
            for(int j = 0 ; j < n ; j++){
                if(s[i] == t[j]){
                    dp[i+1][j+1] = 1+dp[i][j];
                }

                else{
                    dp[i+1][j+1] = max(dp[i][j+1] , dp[i+1][j]);
                }
            }
        }
//done on 15th aug
        return dp[m][n];
    }
};