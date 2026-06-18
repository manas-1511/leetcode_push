class Solution {
public:
    int mySqrt(int x) {
        long long low= 0;
        
        long long  high = x;

        while(low<=high){
            long long  mid = (low+high)/2;
            long long sq = mid*mid;
            if(sq == 1LL*x) return mid;
            else if(sq < 1LL*x){
                low = mid+1;
            }

            else{
                high = mid-1;
            }
        }

        if(high* high  > 1LL*x) return high-1;
        return high ;
    }
};