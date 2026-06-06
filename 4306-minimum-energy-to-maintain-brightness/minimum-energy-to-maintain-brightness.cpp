class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        long long m = intervals.size();
        sort(intervals.begin() , intervals.end());
        long long start  = intervals[0][0];
        long long end  = intervals[0][1];
        long long len = 0 ;
        for(long long i = 1 ; i< m ; i ++){
            long long stcurr = intervals[i][0];
            long long endcurr = intervals[i][1];

            if(stcurr<= end){
                end = max(end , endcurr);
            }

            else{
                len += end-start+1;
                start = stcurr ;
                end = endcurr;
            }
        }

        len += end-start+1;

        if(brightness ==1 || brightness == 2 || brightness ==3) return len;
        if(brightness%3 == 0) return len*(brightness/3);
        return ((brightness/3)+1)*len;
        
    }
};