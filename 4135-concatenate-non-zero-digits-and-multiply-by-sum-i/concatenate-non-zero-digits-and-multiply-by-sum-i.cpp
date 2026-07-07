class Solution {
public:
    long long sumAndMultiply(int n) {
        long long  ans = 0 ;
        long long  sum = 0 ;
        // stack<long long> st ;
        long long place = 1;
        while(n>0){
            long long  d =n%10;
            n = n/10;
            if(d == 0) continue;
            ans += d*place;
            place*=10;
            sum+=d;
        }

        // while(!st.empty()){
        //     ans = ans*10 + st.top();
        //     st.pop();
        // }

        return sum*ans;
    }
};