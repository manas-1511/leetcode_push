class Solution {
public:
    bool isMatch(string s, string p) {
        int m= s.size() , n = p.size();
        vector<int> prev(n+1 , 0);
        prev[0] = 1;
        if(p[0] == '*') prev[1] = 1;
        for(int j = 2 ; j <= n ; j ++){
            if(p[j-1] == '*' && prev[j-1] == 1) prev[j] = 1;
        }

        for(int i = 1 ;i <= m ; i ++){
            vector<int> curr(n+1 , 0);
            for(int j = 1 ; j <= n ; j++){
                if(p[j-1] == s[i-1] || p[j-1] == '?'){
                    curr[j] = prev[j-1];
                }

                else if(p[j-1] == '*'){
                    curr[j] =  prev[j]||curr[j-1];
                }

                else curr[j] = 0; 
            }

            prev = curr;
        }

        return prev[n];


    }
};