class Solution {
public:
    int numDistinct(string s, string t) {
        unsigned long long m = s.size();
        unsigned long long n = t.size();
        vector<unsigned long long> prev(n+1 , 0);
        prev[0] = 1;
       

        for(unsigned long long i = 1; i <= m ; i ++){
            
            
            for(unsigned long long j = n ; j>=1 ; j--){
                if(s[i-1] == t[j-1]){
                    prev[j] = prev[j-1] + prev[j];

                }

                
            }

            
        }

        return prev[n];
    }
};