class Solution {
public:
    //dp
    bool checkValidString(string s) {
        //idx 0 to n
        // cnt 0 to n-1;
        int n = s.size();

        //dp[i][cnt] = dp[i+1][cnt] || dp[i+1][cnt+1] || dp[i+1][cnt-1];
        vector<vector<int>>dp( n+1 , vector<int>(n+2 , 0));
        dp[n][0] = 1 ;

        for(int i = n-1 ; i >= 0 ; i-- ){
            for(int j = n-1; j >= 0 ; j--){
                char c = s[i];
                if(c == '(' && j+1 <= n) dp[i][j] = dp[i+1][j+1];
                if(c == ')' &&  j -1 >=0 ) dp[i][j] = dp[i+1][j-1];
                if(c == '*'){
                    dp[i][j] = dp[i+1][j] ;
                    if(j+1 <= n) dp[i][j] = dp[i][j] || dp[i+1][j+1];
                    if(j-1 >= 0 ) dp[i][j] = dp[i][j] || dp[i+1][j-1];
                }
            }
        }

        return dp[0][0];
    }
};