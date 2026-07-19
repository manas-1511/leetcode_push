class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        long long  ans = s;
        if(n == 1) return ans ;
        long long totalm  = 1LL*(n/2);
        long long  one = totalm -1;
        ans+=(totalm*(1LL)*m)-(one);
        return ans ;
        
    }
};