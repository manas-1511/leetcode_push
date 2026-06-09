class Solution {
public:
    int LCS(string s , string t){
        int m = s.size();
        int n = t.size();

        vector<int> prev(n+1 , 0);
        for(int i = 1 ; i<= m ; i++){
            vector<int> curr(n+1 , 0);
            curr[0] = 0;
            for(int j = 1; j <= n ; j++){
                if(s[i-1] == t[j-1]) curr[j] = 1+prev[j-1];
                else{
                    curr[j] = max(prev[j] , curr[j-1]);
                }
            }

            prev = curr;
        }

        return prev[n];
    
    }
    int minDistance(string word1, string word2) {
        int a = LCS(word1 , word2);
        return word1.size() + word2.size() - 2*a;
    }
};