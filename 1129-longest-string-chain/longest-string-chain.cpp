class Solution {
public:

    bool checkPredecessor(string& s ,string& t){
        if(s.size() != t.size() +1) return false;
        int i = 0 ;
        int j = 0 ;
        //traverse till  string s gets exhausted
        while(i<s.size()){
            if(j < t.size() && s[i] == t[j] ){
                i++ ; j++;
            }

            else i++;
        }
        //if both of them are exhausted then only it is a true predecesor
        if(i == s.size() && j == t.size() ) return true;
        return false;
    }

    static bool comp(string& s , string& t){
        return(s.size() < t.size());
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin() , words.end() , comp);
        vector<int> dp(n , 1);
        int len = 1 ;
        for(int i = 1 ; i < n ; i++){
            for(int j = 0 ; j < i ; j ++){
                if(checkPredecessor(words[i] , words[j]) && dp[j]+1 > dp[i]){
                    dp[i] = dp[j] +1 ;
                    

                }
            }

            len = max(dp[i] , len);
        }

        return len;
    }
};