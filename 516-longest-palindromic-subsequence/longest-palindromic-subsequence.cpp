class Solution {
public:

    int LCS(string& s , string& t){
        int m = s.size();
        int n = t.size();
        vector<int> prev(n+1 , 0);
        for(int i = 1; i <= m ; i++){
                vector<int> curr(n+1 , 0);
            for(int j  = 1 ; j <= n ; j++){
                if(s[i-1] == t[j-1]) curr[j] = 1+ prev[j-1];
                else{
                    curr[j] = max(prev[j] , curr[j-1]);
                }
            }
            prev = curr;

        }

        return prev[n];
    }
    int longestPalindromeSubseq(string s) {
        string t = s;
         reverse(s.begin() , s.end());

        return LCS(s , t);
    }
};