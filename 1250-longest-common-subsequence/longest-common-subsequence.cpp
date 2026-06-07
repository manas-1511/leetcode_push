class Solution {
public:
    int f(string &text1, string &text2 , int i , int j  , vector<vector<int>>& dp){
        if(i < 0 || j < 0) return 0;

        if(dp[i][j] != -1) return dp[i][j] ; 

        if(text1[i] == text2[j]) return dp[i][j] =  1+ f(text1 , text2 , i-1 , j-1 , dp);

        else return dp[i][j] =  max(f(text1 , text2 ,i-1 , j , dp ) , f( text1 , text2 , i , j-1 , dp));

    }
//memoization
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        
        vector<vector<int>> dp( m , vector<int>(n ,-1));
        return f(text1 , text2 , m-1 ,n-1 , dp);


    }
};